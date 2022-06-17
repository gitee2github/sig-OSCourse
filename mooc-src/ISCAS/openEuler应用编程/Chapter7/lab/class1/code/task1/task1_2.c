#include<stdio.h>
#include<netinet/in.h>
union test
{ 
	char str;
	int data;
};
int main()
{
	union test my;
	my.data=0x12345678;
	if(my.str==0x12)
	{
		printf("daduan\n");
	}
	else if(my.str==0x78)
	{
		printf("xiaoduan\n");
	}
	else
		printf("wufabanduan\n");
	int n;
	int i=0;
	printf("本地字节序:\n");
	for(i=0;i<4;i++)
	{
		printf("0x%x\t",*((char*)&my.data+i));
	}
	printf("\n");
	printf("网络字节序:\n");
	n=htonl(my.data);
	for(i=0;i<4;i++)
	{
		printf("0x%x\t",*((char *)&n+i));
	}
	printf("\n");
	return 0;
}
