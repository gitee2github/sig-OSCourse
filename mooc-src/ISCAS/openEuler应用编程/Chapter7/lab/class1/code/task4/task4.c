#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define BACKLOG 10
int main()
{
	int sockfd;
	struct sockaddr_in servaddr;//声明一个sockaddr结构体
	bzero(&servaddr,sizeof(servaddr));//初始化网络协议
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);//指定本地绑定网卡
	servaddr.sin_port=htons(2500);//指定绑定的监听端口
	sockfd=socket(AF_INET,SOCK_STREAM,0);//创建套接字
	if(sockfd<0)
	{
		printf("socket error!\n");
		return -1;
	}
	else
		printf("creat socket success!\n");
	if((bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)))==-1)//利用bind函数将创建好的套接字绑定到本地计算机指定端口上
	{
		printf("bind error!\n");
		return -1;
	}
	else
		printf("bind success!\n");
	if((listen(sockfd,BACKLOG))==-1)//将已经绑定的套接字设置为被动连接监听状态
	{
		printf("listen error!\n");
		return -1;
	}
	else
		printf("listen successful at port 2500\n");
	
	return 0;
}
	
	
