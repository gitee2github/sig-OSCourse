#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>
#define MAXSIZE 1024
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
int main(int argc,char *argv[])
{
    int sockfd,MYPORT;
    struct hostent *he;
    struct sockaddr_in serv_addr;
    char *file_name=NULL;
    struct msg *sm,*rm;
    size_t n=0;
    char buf[MAXSIZE];
    struct timeval start,end;

    sm=(struct msg *)malloc(2048);
    rm=(struct msg *)malloc(2048);
    if(argc!=4) 
    {
        printf("argc error\n");
        exit(EXIT_FAILURE);
    }

    //创建文件名类型的消息
    sm->type=MSG_FILENAME;
    file_name=argv[3];
    sm->len=strlen(file_name);
    memcpy(sm->data,file_name,sm->len);

    FILE *fp=NULL;
    MYPORT=atoi(argv[2]);
    fp=fopen(argv[3],"r");
    if(fp==NULL) 
    {
        perror("fopen error");
        exit(EXIT_FAILURE);
    }


    if((he=gethostbyname(argv[1]))==NULL) 
    {
        perror("gethostbyname error");
        exit(EXIT_FAILURE);
    }

    if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) 
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(MYPORT);
    serv_addr.sin_addr=*((struct in_addr*)he->h_addr);
    memset(&serv_addr.sin_zero,0,8);

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1)
    {
        perror("connect error");
        printf("%s\n",strerror(errno));
        exit(EXIT_FAILURE);
    }

    send(sockfd,(void *)sm,sizeof(struct msg)+sm->len,0);//发送文件名类型的消息
    recv(sockfd,(void *)rm,2048,0);//接收回复类型的消息

    gettimeofday(&start,NULL);//开始传输文件的内容的时间
    while(1) 
    {
        memset(buf,0,sizeof(buf));
        n=fread(buf,1,1024,fp);
        if(n==0) 
        {
            if(feof(fp)) 
            {   
                sm->type=MSG_DONE;
                printf("send MSG_DONE\n");
                send(sockfd,(void *)sm,sizeof(struct msg)+sm->len,0);
                gettimeofday(&end,NULL);//结束传输文件的内容的时间
                printf("发送%s文件总共耗时:%ldms\n",argv[3],1000*(end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000);
                break;
            }
            sm->type=MSG_EXCEPTION;
            printf("send MSG_EXCEPTION\n");
            send(sockfd,(void *)sm,sizeof(struct msg)+sm->len,0);
            break;
        }

        //创建文件内容的消息
        sm->type=MSG_CONTENT;
        sm->len=n;
        memset(sm->data,0,sm->len);
        memcpy(sm->data,buf,n);
        sm->data[n]='\0';
        send(sockfd,(void *)sm,sizeof(struct msg)+sm->len,0);
        recv(sockfd,(void *)rm,2048,0);
    }

    free(sm);
    free(rm);
    close(sockfd);
    return 0;
}


