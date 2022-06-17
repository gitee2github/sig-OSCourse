#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH "./num1"
int flag=0;
int getint(FILE *fp)
{
    int tem=0;
    char s[8];
    if( fgets(s,5,fp)==NULL)
    {
	printf("读取文件结束！\n");
	//s[strlen(s)-1]='\0';
        flag=1;
    	return 0;
    }	
    
    tem=atoi(s);
    return tem;
	
}

int main()
{
    int x,y;
	FILE *fp=NULL;
	fp=fopen(PATH,"r");
	if(fp==NULL)
	{
		printf("Failed");
		return -1;
	}
    while(flag==0)
    {
        printf("=========================\n");
	x=getint(fp);
        printf("input x:%d\n",x);
        y=getint(fp);
        printf("input y:%d\n",y);
        printf("%d+%d=%d\n",x,y,x+y);
    }
	fclose(fp);
    return 0;
}
