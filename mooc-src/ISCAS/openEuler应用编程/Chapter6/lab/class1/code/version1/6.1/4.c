#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>  // 修改为日历时间的函数头文件

int main(int argc, char* argv[])
{
	if(argc < 2) 
	{
		printf("ERROR:Please input the file name.\n");
		return 0;
	}

	struct stat buf;
	char *path = argv[1];
	int ret;
	if(ret = stat(path, &buf) != 0)
	{
		printf("ERROR: execute stat function error.\n");
		return 0;
	}
	
	printf("User ID is: %u\n", buf.st_uid);
	printf("Group ID is: %u\n", buf.st_gid);
	printf("File size is: %d\n", buf.st_size);
	printf("last access time is: %s\n", ctime(&(buf.st_atime)));
	printf("last modify time is: %s\n", ctime(&(buf.st_mtime)));

	return 0;
}
