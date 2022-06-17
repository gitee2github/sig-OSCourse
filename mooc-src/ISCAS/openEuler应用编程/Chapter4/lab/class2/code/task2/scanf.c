#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x,y;
	while(1)
	{
		printf("======================\n");
		printf("Please input two number:\n");
		scanf("%d %d",&x,&y);
		printf("%d+%d=%d\n",x,y,x+y);
	}
	return 0;
} 
