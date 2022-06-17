#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#define SIZE 10000
int main()
{
	DIR*dirptr=NULL;
	struct dirent*entry;
	char buf[SIZE];
	printf("please input a file pathname:\n");
	fgets(buf,SIZE,stdin);
	int i=strlen(buf);
	buf[i-1]='\0';
	if((dirptr=opendir(buf))==NULL){
		printf("open dir error!\n");
		return 1;
	}
	else{	
		while(entry=readdir(dirptr))
		printf("%s\n",entry->d_name);
		closedir(dirptr);
	}
	return 0;
}

