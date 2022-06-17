#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
char needfile[256];
void scanDirfiles(char*path)
{
	struct dirent *file;
	DIR *d;
	char fullpath[500];
	d=opendir(path);
	while(file=readdir(d))
	{
			//过滤 . ..
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0){
			continue;
		}
		sprintf(fullpath, "%s/%s", path, file->d_name);
		if(file->d_type == DT_DIR){
			scanDirfiles(fullpath);
		}else{
			if(strcmp(needfile, file->d_name) == 0){
				printf("has found : %s\n", fullpath);
				exit(1);
			}
		}
	}
	closedir(d);
}
int main(int argc,char*argv[])
{
	if(argc<3)
	{
		printf("error:please input dir and file\n");
		exit(1);
	}
	char path[256];
	if(chdir(argv[1])==-1)
	{
		perror("arg");
		exit(1);
	}
	getcwd(path,255);
	strncpy(needfile,argv[2],strlen(argv[2]));
	needfile[strlen(argv[2])]='\0';
	scanDirfiles(path);
	printf("NOT FOUND!\n");
	return 0;
}
