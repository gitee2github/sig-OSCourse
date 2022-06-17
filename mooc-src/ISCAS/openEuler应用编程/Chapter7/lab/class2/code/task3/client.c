#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 100
int main(int argc,char **argv)
{
    int sockfd;
    char buff[MAXLINE];
    int n;
    struct sockaddr_in clientaddr;
    if(argc<2){
        printf("arg error\n");
        exit(1);
    }
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd <0){
        perror("socket error!");
        exit(1);
    }
    clientaddr.sin_family=AF_INET;
    clientaddr.sin_port=htons(2500);
    inet_aton(argv[1],&clientaddr.sin_addr);
    if(connect(sockfd,(struct sockaddr *)&clientaddr,sizeof(clientaddr))<0){
        perror("connect error!");
        exit(1);
    }
    else{
        while(1){
            printf("input sth:\n");
            gets(buff);
            send(sockfd,buff,sizeof(buff),0);

            n=recv(sockfd,buff,sizeof(buff),0);
            if(n>0)
                printf("server say %s\n",buff);
            if(strcmp(buff,"exit")==0)
                break;
        }
    }
    return 0;
}


