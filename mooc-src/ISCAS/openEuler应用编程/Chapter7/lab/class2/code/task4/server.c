#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000
#define BACKLOG 10
int main(int argc,char*argv[])
{
    int listenfd,connfd,n;
    socklen_t len;
    struct sockaddr_in servaddr,cliaddr;
    char buff[MAXLINE];
    time_t ticks;
    if((listenfd=socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket error!");
        exit(1);
    }
    bzero((void*)&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(2500);
    if((bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))==-1){
        perror("bind error!");
        exit(1);
    }
    if((listen(listenfd,BACKLOG)==-1)){
        perror("listen error");
        exit(1);
    }
    while(1)
    {
        len=sizeof(cliaddr);
        connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&len);
        inet_ntop(AF_INET,&cliaddr.sin_addr,buff,sizeof(buff));
        printf("%s,port %d\n",buff,(int)ntohs(cliaddr.sin_port));
        while((n=recv(connfd,buff,sizeof(buff),0))>0)
        {
            printf("recvlen=%d\n",n);
            if(n>0){
                buff[n]='\0';
                printf("%s\n",buff);
                n=send(connfd,"hi this is server!\n",sizeof("Hi this is server!"),0);
            }
        }
        close(connfd);
    }
}
