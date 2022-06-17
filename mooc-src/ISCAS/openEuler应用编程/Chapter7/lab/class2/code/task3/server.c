#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#define BACKLOG 10
#define MAXLINE 100
void sig_chld(int signo)
{
    pid_t    pid;
    int      stat;

    while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("child %d terminated\n", pid);
    return;
}
int main(int argc,char * argv[])
{
    signal(SIGCHLD,sig_chld);
    int sockfd,connfd;
    pid_t pid;
    int n,len;
    char buff[MAXLINE],clientword[MAXLINE],bufftime[50],content[MAXLINE];
    struct sockaddr_in serveraddr,clientaddr;
    time_t ticks;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        printf("socket error\n");
        return -1;
    }
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(2500);
    serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);
    if(bind(sockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))<0){
        printf("bind error\n");
        return -1;
    }
    if(listen(sockfd,BACKLOG)<0){
        printf("listen error\n");
        return -1;
    }
    while(1){
        len = sizeof(clientaddr);
        connfd = accept(sockfd, (struct sockaddr*)&clientaddr, &len);
        if((pid = fork()) == 0){
            close(sockfd);
            inet_ntop(AF_INET, &clientaddr.sin_addr, buff, sizeof(buff));
            printf("connection from %s ,port %d,my pid is %d\n", buff,ntohs(clientaddr.sin_port),getpid());
            //recv client msg and send msg to client
            while(1){
                n = recv(connfd,content,sizeof(content),0);
                memset(&ticks,0,sizeof(ticks));
                time(&ticks);
                if(n > 0){
                    snprintf(buff,sizeof(buff),"i am subprocess,my pid is %d,now time is %s",getpid(),ctime(&ticks));
                    send(connfd,buff,sizeof(buff),0);
                    content[n] = '\0';
                    if(strcmp(content,"exit") == 0){
                        printf("Client %s exit!\n",buff);
                        break;
                    }
                    else
                        printf("%s\n",content);
                }
            }//while
            close(connfd);
            exit(0);
        }//while
        close(connfd);
    }
} 

