#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<stdlib.h>
#define MAXLINE 1024
int main()
{
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;
	socklen_t len;
	char buff[MAXLINE];
	int i,n;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd<0)
	{
		printf("socket error!\n");
		exit(1);
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(2500);
	if(bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr))==-1)
	{
		printf("bind error!\n");
		exit(1);
	}
	while(1)
	{
		len=sizeof(servaddr);
		n=recvfrom(sockfd,buff,MAXLINE,0,(struct sockaddr *)&servaddr,&len);
	//	n=recvfrom(sockfd,buff,MAXLINE,0,NULL,0);
		if(n<0)
		{
			perror("recvfrom error!\n");
			exit(1);
		}
		if(sendto(sockfd,buff,n,0,(struct sockaddr *)&servaddr,sizeof(servaddr))<0)
		{
			perror("sendto error!\n");
			exit(1);
		}
	close(sockfd);
	return 0;
	}
}
		
