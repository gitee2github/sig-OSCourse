#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
void scanDirfiles(char *path)
{
	struct dirent *file;
	DIR *d;
	char fullpath[500];
	d = opendir(path);
	if(d == NULL){
		perror("opendir");
		exit(1);
	}
	while(file = readdir(d)){
		//过滤 . ..
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0){
			continue;
		}
		if(file->d_type == DT_DIR){
			sprintf(fullpath, "%s/%s", path, file->d_name);
			scanDirfiles(fullpath);
		}else{
			printf("%s/%s\n", path, file->d_name);
		}
	}
	closedir(d);
}
int main(int argc, char *argv[])
{
	if(argc == 1){
		printf("error : please input dir\n");
		exit(1);
	}	
	char path[256];

	if(chdir(argv[1]) == -1){
		perror("arg");
		exit(1);
	}
	getcwd(path, 255);
	scanDirfiles(path);
	return 0;
}

