#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

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
//	buf.st_mode &= 0;
	buf.st_mode = S_IRUSR | S_IWUSR  | S_IRGRP  | S_IROTH;
	if(ret = chmod(path, buf.st_mode) != 0)	
	{
		printf("ERROR: execute chmod function error.\n");
		return 0;
	}
	printf("The file authority is: ");
	int i;
	for(i = 2; i >= 0; i--)
	{
		if(buf.st_mode & 1 << (i * 3 + 2))
			printf("r");
		else
			printf("-");
			
		if(buf.st_mode & 1 << (i * 3 + 1))
			printf("w");
		else
			printf("-");

		if(buf.st_mode & 1 << (i * 3 + 0))
			printf("x");
		else
			printf("-");
	}
	printf("\n");
	
	return 0;
}
