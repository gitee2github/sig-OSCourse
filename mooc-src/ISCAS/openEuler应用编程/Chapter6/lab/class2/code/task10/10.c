#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc,char*argv[])
{
	DIR*d;
	struct dirent *file;
	int flag=0;
	if(argc<=2){
		printf("error:need dir and new dir\n");
		exit(1);
	}
	if((d=opendir(argv[1]))==NULL){
		perror("opendir error");	
		exit(1);
	}
	while(file=readdir(d)){
		if(strcmp(file->d_name,".")==0||strcmp(file->d_name,"..")==0)
			continue;
		if(file->d_type==DT_DIR&&(strcmp(file->d_name,argv[2])==0))
			flag=1;
	}
	closedir(d);
	if(chdir(argv[1])==-1){
		perror("chdir error!");
		exit(1);
	}
	if(flag==0){
		if(mkdir(argv[2],0755)==-1)
			perror("mkdir error");
		else
			printf("mkdir success!\n");
	}
	else
		printf("fail:has exist\n");

	return 0;
}
