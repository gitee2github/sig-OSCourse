#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#define SIZE 100000
int main()
{
	char pathname[SIZE];
	printf("please input a file pathname:\n");
	fgets(pathname,SIZE,stdin);
	PrintFileName(pathname);
	return 0;
}
int PrintFileName(char*pathname)
{
	struct stat st;
	struct dirent *entry;
	DIR*dirptr=NULL;
	int i=strlen(pathname);
	if(pathname[i-1]=='\n')
		pathname[i-1]='\0';
	if((dirptr=opendir(pathname))==NULL)
	{
		printf("open dir error\n");
		return 1;
	}
	else{
		while(entry=readdir(dirptr))
		{
			char tmp[SIZE];
			if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
				continue;
			if(pathname[i-2]=='/')
				sprintf(tmp,"%s%s",pathname,entry->d_name);
			else
				sprintf(tmp,"%s/%s",pathname,entry->d_name);
			stat(tmp,&st);
			if(S_ISDIR(st.st_mode))
				PrintFileName(tmp);
			else
				if(st.st_mode&S_IXOTH)
					printf("%s\n",entry->d_name);
			
		}
	}
	return 0;
}
