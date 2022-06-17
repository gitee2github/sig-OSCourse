#ifdef SOLARIS
#define PSCMD "ps -a -o pid,ppid,s,tt,comm"
#else
#define PSCMD "ps -o pid,ppid,state,tty,command"
#endif
#include<sys/types.h>
int main(void){
	pid_t pid;
	if((pid = fork())<0)
		printf("fork error");
	else if(pid == 0)
		exit(0);
	sleep(4);
	system(PSCMD);
	exit(0);
}
