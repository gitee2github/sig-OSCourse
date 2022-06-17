#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *pwd;
    int ret;

    ret = chroot("/home/ruby");
    if(ret != 0) 
	{
        perror("chroot:");
        exit(-1);
    }
    pwd = getcwd(NULL, 0);
    printf("after chroot,getcwd is [%s]\n",pwd);
    free(pwd);

     chdir("/test");
    pwd = getcwd(NULL, 0);
    printf("after chdir /,getcwd is [%s]\n",pwd);
    free(pwd);

    return 0;
}
