#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
	int num,i;
	char buf[100][100];
	printf("Please input num\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		scanf("%s",buf[i]);
	
	for(i=0;i<num;i++)
		printf("%s\n",buf[i]);
}
