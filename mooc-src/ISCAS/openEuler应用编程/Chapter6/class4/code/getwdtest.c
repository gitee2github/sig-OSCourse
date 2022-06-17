#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
 //  char *cwd;
   char buf[256];
    getwd(buf);
//   if(!cwd)
  //{
    // printf("error:getcwd fail");
     //return 0;
 // }
  printf("path from buf=%s,cwd\n",buf);
  
  return 0;
}
