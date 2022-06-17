#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<errno.h>
#define MAXLINE 1024
int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	int n;
	if(argc!=2)
	{
		printf("error!\n");
		exit(1);
	}
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(2500);
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	printf("client says:");
	while(fgets(buff,MAXLINE,stdin)!=NULL)
	{
		n=sendto(sockfd,buff,sizeof(buff),0,(struct sockaddr *)&servaddr,sizeof(servaddr));
		if(n>0)
		{
			n=recvfrom(sockfd,buff,MAXLINE,0,NULL,0);
			if(n>0)
				printf("server says:%s\n",buff);
		}
	close(sockfd);
	}
	return 0;
}
