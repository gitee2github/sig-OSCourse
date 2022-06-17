#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
int main()
{
	int fd;
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		printf("socket error!\n");
		return -1;
	}
	else
	{
		printf("creat socket sucessful!\n");
		printf("fd=%d\n",fd);
	}
	return 0;
}
