#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAXLINE 100
#define BACKLOG 10
#define MAXRECVLEN 1000
int main( int argc, char ** argv )
{
    int listenfd, connfd,n;
    socklen_t len;
    struct sockaddr_in servaddr, cliaddr;
    char buff[MAXLINE];
    char recvbuf[MAXRECVLEN]={0};
    char sendbuf[MAXLINE]={0};
    FILE *fp=NULL;
    time_t ticks;
    if(argc!=2)
    {
        printf("input file name\n");
        return 0;
    }
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket error!");
        exit(1);
    }
    bzero((void *)&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(2500);
    if((bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) == -1){
        perror("bind error!");
        exit(1);
    }
    if( (listen(listenfd, BACKLOG)) == -1 ){
        perror("listen error!");
        exit(1);
    }
    while(1)
    {
        len = sizeof(cliaddr);
        connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
        inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff));
        printf(" %s ,port %d\n", buff,ntohs(cliaddr.sin_port));

        fp=fopen(argv[1],"w");
        if(fp==NULL)
        {
            printf("fopen error\n");
            return 0;
        }
        n=recv(connfd,recvbuf,sizeof(recvbuf),0);
        while(n>0)
        {
            //printf("%s\n",buff);
            fwrite(recvbuf,1,n,fp);
            snprintf(sendbuf,sizeof(sendbuf),"Hi,server receive %d string!",n);
            n = send(connfd,sendbuf,strlen(sendbuf),0);
            memset(recvbuf,0,sizeof(recvbuf));
            n=recv(connfd,recvbuf,sizeof(recvbuf),0);

        }
        printf("file %s write over!\n",argv[1]);
        close(connfd);
        // printf("%s\n",buff);
        fclose(fp);
    }
}

