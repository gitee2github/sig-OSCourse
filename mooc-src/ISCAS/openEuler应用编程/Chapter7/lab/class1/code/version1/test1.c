#include<stdio.h>
#include<netinet/in.h>
int main()
{
	int num=0x12345678;
	int n;
	int i=0;
	printf("本地字节序:\n");
	for(i=0;i<4;i++)
	{
		printf("0x%x\t",*((char*)&num+i));
	}
	printf("\n");
	printf("网络字节序:\n");
	n=htonl(num);
	for(i=0;i<4;i++)
	{
		printf("0x%x\t",*((char *)&n+i));
	}
	printf("\n");
	return 0;
}
