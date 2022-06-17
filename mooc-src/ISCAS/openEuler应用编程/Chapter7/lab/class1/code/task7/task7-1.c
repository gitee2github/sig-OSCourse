#include<stdio.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

#include<string.h>
#include<sys/types.h>
#define MYPORT 0//服务器端的端口号设置为0

#define BACKLOG 10
int main()
{
	int sockfd,new_fd;
	
	struct sockaddr_in my_addr;
	struct sockaddr_in their_addr;

	char buf[200]={0};

	int pid;

	int sin_size;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		perror("sockfd error");
		exit(1);
	}
	else

	
	my_addr.sin_family=AF_INET;
	my_addr.sin_port=htons(MYPORT);//转换为网络字节顺序
	my_addr.sin_addr.s_addr=INADDR_ANY;//自动填本级IP
	bzero(&(my_addr.sin_zero),8);
	if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))==-1)
	{
		perror("bind error");
		exit(1);
	}

	if(listen(sockfd,BACKLOG)==-1)
	{
		perror("listen error");
		exit(1);
	}
	struct sockaddr_in serv;
	char serv_ip[20]={0};
	socklen_t serv_len=sizeof(serv);
	getsockname(sockfd,(struct sockaddr *)&serv,&serv_len);
	inet_ntop(AF_INET,&serv.sin_addr,serv_ip,sizeof(serv_ip));
	printf("ip:%s,服务器自动指定的端口号为:%d\n",serv_ip,ntohs(serv.sin_port));

	return 0;
}

