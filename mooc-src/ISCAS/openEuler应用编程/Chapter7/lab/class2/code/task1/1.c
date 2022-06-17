#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define <AXLINE 100
#define BACKLOG 10
int main(int argc,char*argv[])
{
    int listenfd,connfd;
    pid_t pid;
    socklen_t len;
    struct sockaddr_in servaddr,cliaddr;
    char buff[MAXLINE];
    time_t ticks;
    if((listenfd=socket(AF_INET,SOCK_STRWAM,0))==-1)
    {
        perror("socket error!");
        exit(1);
    }
    bzero(&servaddr,sizeof(servaddr));
    servadd.sin_family=AF_INET;
    servaddr.sin_addr.s_adddr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(2500);
    if((bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))==-1){
        perror("bind error");
        exit(1);
    }
    if((listen(listenfd,BACKLOG))==-1){
        perror("listen error!");
        exit(1);
    }
    for(;;){
        len=sizeof(cliaddr);
        connfd=accept(listenfd,(sttruct sockaddr*)&cliaddr,&len);
        if((pid=fork())==0){
            close(listenfd);
            inet_ntop(AF_INET,&cliaddr.sin_addr,buff,sizeof(buff));
            printf("connection from %s,port %d\n",buff,ntohs(cliaddr.sin_port));
            close(connfd);
            exit(0);
        }
        close(connfd);
    }
}
