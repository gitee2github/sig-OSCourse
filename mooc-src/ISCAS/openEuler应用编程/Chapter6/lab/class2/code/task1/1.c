#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
int main(void)
{
	struct stat st;
	char buf[100];
	printf("please input a file pathname:\n");
	fgets(buf,100,stdin);
	int i=strlen(buf);
	buf[i-1]='\0';
	stat(buf,&st);
	if(S_ISDIR(st.st_mode))
		printf("%s is a directory.\n",buf);
	else
		printf("%s is not a directory.\n",buf);
	return 0;
	
}
