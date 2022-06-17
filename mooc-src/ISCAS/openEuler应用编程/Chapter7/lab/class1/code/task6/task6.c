#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<errno.h>
#include<netdb.h>
#include<sys/types.h>
#define BACKLOG 10
#define MAXLINE 100
int main(int argc,char *argv[])
{
	int sockfd,newsockfd;
	char buff[MAXLINE];
	socklen_t len;
//	int errnum;
	char *message;
	struct sockaddr_in servaddr;//声明一个sockaddr结构体
	sockfd=socket(AF_INET,SOCK_STREAM,0);//创建套接字
	if(argc!=2)
	{
		printf("error!\n");
		return -1;
	}
	if(sockfd<0)
	{
		printf("socket error!\n");
		return -1;
	}
	else
		printf("creat socket success!\n");
	bzero(&servaddr,sizeof(servaddr));//初始化网络协议
        servaddr.sin_family=AF_INET;
        servaddr.sin_port=htons(2500);//指定绑定的监听端口
	if(inet_pton(AF_INET,argv[1],&servaddr.sin_addr)==-1)
	{
		printf("inet_pton error!\n");
		return -1;
	}
	if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(struct sockaddr))==-1)
	{
		printf("can not connect to %s\n",argv[1]);
//		message=strerror(errnum);
		printf("%s\n",strerror(errno));
		exit(0);
	}
	else
	{
		printf("connect to %s successfully\n",argv[1]);
	}
	close(sockfd);
	return 0;
}
	
	
