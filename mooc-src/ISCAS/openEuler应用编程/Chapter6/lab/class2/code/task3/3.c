#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char *argv[]){
	struct stat st;			//属性
	DIR *d;				//目录流
	struct dirent *file;		//文件
	char filePath[256];		//文件全部路径
	char dirName[100];		//文件绝对路径
	//参数是否正确
	if(stat(argv[1], &st) == -1){	
		perror("stat");
		exit(1);
	}
	//必须输入目录
	if(!S_ISDIR(st.st_mode)){
		printf("erro : please input dir\n");
		exit(1);
	}
	//更改工作目录前打开目录流
	if((d = opendir(argv[1])) == NULL){
		perror("opendir");
		exit(1);
	}
	//更改工作目录获得囧对路径
	chdir(argv[1]);
	getcwd(dirName, 100);
	//读取目录下文件
	while(file = readdir(d)){
		//过滤 . ..
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0){
			continue;
		}
		//生成绝对路径
		sprintf(filePath, "%s/%s", dirName, file->d_name);	
		printf("%s\n", filePath);
	}
	closedir(d);
	return 0;
}

