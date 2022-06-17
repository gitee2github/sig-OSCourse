/* 将/etc/passwd 的所有者和组都设为root */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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
	printf("Group ID before change is: %u\n", buf.st_gid);

	if(ret = chown(path, -1, 0) != 0)
	{
		printf("ERROR: execute chown function error.\n");
		return 0;
	}

	if(ret = stat(path, &buf) != 0)
	{
		printf("ERROR: execute stat function error.\n");
		return 0;
	}
	printf("Group ID after change is: %u\n", buf.st_gid);

	return 0;
}
