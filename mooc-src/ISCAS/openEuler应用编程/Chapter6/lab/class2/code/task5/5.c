#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define SIZE 100
int count_dir=0,count_lnk=0,count_reg=0,count_chr=0,count_blk=0,count_sock=0;
void PrintFileName(char*pathname)
{
	struct dirent*entry;
	struct stat st;
	DIR *dirptr;
	if((dirptr=opendir(pathname))==NULL)
	{
		printf("open dir error\n");
		exit(0);
	}
	else
	{
		while(entry=readdir(dirptr))
		{
			char tmp[SIZE];
			if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
				continue;
			sprintf(tmp,"%s/%s",pathname,entry->d_name);
			stat(tmp,&st);
			if(S_ISDIR(st.st_mode)){
				count_dir++;
				PrintFileName(tmp);
				printf("%s\n",tmp);
			}
			else{
				printf("%s\n",tmp);
				if(S_ISLNK(st.st_mode))
					count_lnk++;
				if(S_ISREG(st.st_mode))
					count_reg++;
				if(S_ISCHR(st.st_mode))
					count_chr++;
				if(S_ISBLK(st.st_mode))
					count_blk++;
				if(S_ISSOCK(st.st_mode))
					count_sock++;
			}
		}
	}
}
int main(void)
{
	char *pathname;
	pathname=(char*)getcwd(NULL,0);
	printf("Current path is %s.\n",pathname);
	PrintFileName(pathname);
	printf("DIR number:%d\n",count_dir);
	printf("LNK nnumber:%d\n",count_lnk);
	printf("REG number:%d\n",count_reg);
	printf("CHR number:%d\n",count_chr);
	printf("BLK number:%d\n",count_blk);
	printf("SOCK number:%d\n",count_sock);
}
