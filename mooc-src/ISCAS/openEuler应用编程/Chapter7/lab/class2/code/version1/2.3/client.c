#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc,char ** argv)
{
	int sockfd,n;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	if(argc < 2)
	{
		printf("usage: %s IP\n",argv[0]);
		exit(1);
	}
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket failed!");
		exit(1);
	}
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(2500);
	inet_aton(argv[1],&servaddr.sin_addr);
	
	if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) < 0)
	{
		printf("cannot connect to %s , exit!\n", argv[1]);
		printf("%s\n", strerror(errno));
		exit(1);
	}else
	{
		gets(buff);
		send(sockfd,buff,sizeof(buff),0);
		n = recv(sockfd,buff,sizeof(buff),0);
		if(n > 0)
		{
			buff[n] = '\0';
			printf("Server say: %s\n",buff);
		}
	}

	return 0;
}
