#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
   char *path = "/home";
   char *cwd = NULL;
   cwd = getcwd(NULL,0);
   printf("before change dir::%s\n",cwd);
   chdir(path);
   cwd = getcwd(NULL,0);
   printf("current working directory:%s\n",cwd);
   free(cwd);
}
