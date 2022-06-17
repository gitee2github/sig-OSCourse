#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100
#define BACKLOG 10

int main( int argc, char ** argv )
{
	int listenfd, connfd,n;
	pid_t pid;
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;
	char buff[MAXLINE];
	time_t ticks;

	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
	perror("socket error!");
	exit(1);
	}

	bzero(&servaddr,sizeof(servaddr));
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
	for(;;){
	len = sizeof(cliaddr);
	connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
	if((pid = fork()) == 0)
	{
		close(listenfd);
		inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff));/*地址由二进制数转换为点分十进制*/
		printf("connection from %s ,port %d\n", buff,ntohs(cliaddr.sin_port));
		n = recv(connfd,buff,sizeof(buff),0);
		time(&ticks);
		if(n > 0)
		{
			buff[n] = '\0';
			printf("%s\n",buff);
			snprintf(buff,sizeof(buff),"Hi! server time: %.24s\r\n",ctime(&ticks));
			n = send(connfd,buff,MAXLINE,0);
		}
		close(connfd);
		exit(0);
	}
	close(connfd);
	}
}
