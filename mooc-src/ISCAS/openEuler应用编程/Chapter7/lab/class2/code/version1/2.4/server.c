#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define MAXLINE 100
#define BACKLOG 10

 void sig_chld(int signo)
{
      pid_t    pid;
      int      stat;

      while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
          printf("child %d terminated\n", pid);
      return;
}


int main( int argc, char ** argv )
{
	signal (SIGCHLD, sig_chld);
	int listenfd, connfd,n;
	pid_t pid;
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;
	char buff[MAXLINE];
	char content[MAXLINE];
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
		inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff));
		printf("connection from %s ,port %d\n", buff,ntohs(cliaddr.sin_port));
		while(1)
		{	
			n = recv(connfd,content,sizeof(content),0);
			time(&ticks);
			if(n > 0)
			{
			printf("%s  %.24s say:\r\n",buff,ctime(&ticks));
			content[n] = '\0';
			if(strcmp(content,"exit") == 0)
			{
				printf("Client %s exit!\n",buff);
				break;
			}
			else
				printf("%s\n",content);
			}
		}
		close(connfd);
		exit(0);
	}
	close(connfd);
	}
}
