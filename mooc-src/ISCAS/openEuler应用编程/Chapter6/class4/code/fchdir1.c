#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
   int fd;
   char *cwd = NULL;
   fd = open("/tmp",O_RDONLY);
   cwd = getcwd(NULL,0);
   printf("before change dir::%s\n",cwd);
   fchdir(fd);
   cwd = getcwd(NULL,0);
   printf("current working directory:%s\n",cwd);
   free(cwd);
}
