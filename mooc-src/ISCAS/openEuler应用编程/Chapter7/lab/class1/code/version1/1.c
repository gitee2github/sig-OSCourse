#include<stdio.h>
bool main()
{
	int i;
	char *p=(char *)&i;
	return (*p==1);
}
