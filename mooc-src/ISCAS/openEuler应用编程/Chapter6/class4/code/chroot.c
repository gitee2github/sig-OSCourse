#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    chroot("/home/drc");
    printf("after chroot,getcwd is [%s]\n",getcwd(NULL, 0));
    chdir("/test");  
    printf("after chdir /,getcwd is [%s]\n",getcwd(NULL, 0));
    return 0;
}

