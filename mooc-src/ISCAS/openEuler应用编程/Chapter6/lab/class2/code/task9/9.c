#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#define SIZE 10000
int PrintFileName(char*pathname,int uid_name)
{
	struct stat st;
	struct dirent*entry;
	DIR*dirptr=NULL;
	if((dirptr=opendir(pathname))==NULL)
	{
		perror("open dir error\n");
		return 1;
	}
	else
	{
		while(entry=readdir(dirptr))
		{	
			char tmp[SIZE];
			if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
				continue;
			int i=strlen(pathname);
			if(pathname[i-1]=='/')
				sprintf(tmp,"%s%s",pathname,entry->d_name);
			else
				sprintf(tmp,"%s/%s",pathname,entry->d_name);
			stat(tmp,&st);
			if(S_ISDIR(st.st_mode))
				PrintFileName(tmp,uid_name);
			if(st.st_uid==uid_name)
				printf("%s\n",tmp);

		}
	}
	return 0;
}
int main()
{
	char pathname[SIZE];
	char username[SIZE];
	printf("please input a file pathname:\n");
	fgets(pathname,SIZE,stdin);
	int i=strlen(pathname);
	pathname[i-1]='\0';
	printf("please input a username:\n");
	fgets(username,SIZE,stdin);
	int j=strlen(username);
	username[j-1]='\0';
	struct passwd*pwd=getpwnam(username);
	if(!pwd)
	{
		printf("%s id not exist!\n",username);
		return -1;
	}
	int uid_name=pwd->pw_uid;
	PrintFileName(pathname,uid_name);
	return 0;
}
