#include <stdio.h> 
#include <unistd.h>
#include <sys/times.h>  
  
static void pr_times(clock_t,struct tms *,struct tms*);  
static void do_cmd(char *);  
  
int main(int argc, char *argv[]){  
    int i;  
    setbuf(stdout,NULL);//标准输出是无缓冲的  
  
    for(i=1;i<argc;i++){  
        do_cmd(argv[i]);  
    }  
    exit(0);  
}  
static void do_cmd(char *cmd){  
    struct tms tmsstart,tmsend;  
    clock_t start,end;  
    int status;  
  
    printf("\ncommand: %s\n",cmd);  
    if((start=times(&tmsstart))==-1)//times的返回值就是当前流逝的墙上时钟时间  
        printf("times error");  
    if((status=system(cmd))<0){  
        printf("system() error");  
    }  
    if((end=times(&tmsend))==-1){//需要start和end两者相减得到运行的时间  
        printf("times error");  
    }  
  
    pr_times(end-start,&tmsstart,&tmsend);  
    //pr_exit(status);  
}  
  
static void pr_times(clock_t real,struct tms *tmsstart,struct tms *tmsend){  
    static long clktck=0;  
  
    if(clktck==0){  
        if((clktck=sysconf(_SC_CLK_TCK))<0){//每秒的滴答数，我们用这个将滴答数转化为秒数  
            printf("sysconf error");  
        }  
    }  
    printf("\treal:\t%7.2f\n",real/(double)clktck);  
    printf("\tuser:\t%7.2f\n",(tmsend->tms_utime-tmsstart->tms_utime)/(double)clktck);  
    printf("\tsys :\t%7.2f\n",(tmsend->tms_stime-tmsstart->tms_stime)/(double)clktck);  
    printf("\tchild user:\t%7.2f\n",(tmsend->tms_cutime-tmsstart->tms_cutime)/(double)clktck);  
    printf("\tchild sys:\t%7.2f\n",(tmsend->tms_cstime-tmsstart->tms_cstime)/(double)clktck);  
  
}
