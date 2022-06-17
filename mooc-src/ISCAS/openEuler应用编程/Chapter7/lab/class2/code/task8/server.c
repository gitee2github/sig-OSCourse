#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/time.h>
#define BACKLOG 10
#define MAXSIZE 1000
#define MSG_FILENAME 1
#define MSG_CONTENT 2
#define MSG_ACK 3
#define MSG_DONE 4
#define MSG_EXCEPTION 5
struct msg
{
    int type;
    int len;
    char data[0];
};
void zhuanhuan(char *file_name)
{
    int i,j=0;
    i=strlen(file_name);
    char tmp[MAXSIZE]={0};
    for(i;file_name[i]!='/';i--);
    for(j=0;file_name[i]!='\0';i++)
        tmp[j++]=file_name[i+1];
    tmp[j]='\0';
    strcpy(file_name,tmp);
}
int main(int argc,char *argv[])
{
    int sockfd;
    struct sockaddr_in my_addr; 
    int new_fd,sin_size;
    struct sockaddr_in my_client_addr;
    int MYPORT;
    struct msg *sm,*rm;
    sm=(struct msg*)malloc(2048);
    rm=(struct msg*)malloc(2048);
    int len;
    char file_name[MAXSIZE];
    int n;
    char buf[MAXSIZE];
    FILE *fp=NULL;
    struct timeval start,end;   
    if(argc!=2)
    {
        perror("argc error");
        exit(EXIT_FAILURE);
    }
    MYPORT=atoi(argv[1]);
    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) 
    {
        perror("socket error\n");
        exit(EXIT_FAILURE);
    }
    my_addr.sin_family=AF_INET;
    my_addr.sin_port=htons(MYPORT);
    my_addr.sin_addr.s_addr=INADDR_ANY;
    memset(&(my_addr.sin_zero),0,8);
    if((bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr)))==-1) 
    {
        perror("bind error\n");
        exit(EXIT_FAILURE);
    }   
    if(listen(sockfd,BACKLOG)==-1) 
    {
        perror("listen error\n");
        exit(EXIT_FAILURE);
    }   
    sin_size=sizeof(struct sockaddr_in);
    bzero(&my_client_addr,sin_size);
    new_fd=accept(sockfd,(struct sockaddr *)&my_client_addr,&sin_size);
    if(new_fd==-1) 
        exit(EXIT_FAILURE);
    sm->type=MSG_ACK;
    sm->len=0;
    len=recv(new_fd,(void *)rm,2048,0);
    send(new_fd,(void*)sm,sizeof(struct msg),0);
    if(rm->type==MSG_FILENAME)
    {
        memset(file_name,0,256);
        memcpy(file_name,rm->data,rm->len);
    }
    zhuanhuan(file_name);
    fp=fopen(file_name,"w");
    memset(buf,0,MAXSIZE);
    gettimeofday(&start,NULL);//开始接收文件内容的时间
    while(1) 
    {
        len=recv(new_fd,(void *)rm,2048,0)-sizeof(struct msg);
        send(new_fd,(void *)sm,sizeof(struct msg),0);
        fseek(fp,0,SEEK_END);
        if(rm->type == MSG_EXCEPTION)
        {
            printf("MSG_EXCEPTION\n");
            break;
        }
        if(rm->type == MSG_DONE)
        {
            printf("MSG_DONE\n");
            gettimeofday(&end,NULL);//接收文件内容结束的时间
            printf("接收%s文件总共耗时:%ldms\n",file_name,1000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000);
            break;
        }
        if(rm->type==MSG_CONTENT)
        {
            memset(buf,0,MAXSIZE);
            memcpy(buf,rm->data,rm->len);

            fwrite(buf,1,len,fp);
        }
        else
            break;

    }       
    fclose(fp);
    close(sockfd);
    free(sm);
    free(rm);
    exit(0);
}


