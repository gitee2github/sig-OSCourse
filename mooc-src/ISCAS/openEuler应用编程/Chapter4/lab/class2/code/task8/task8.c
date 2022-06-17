#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    char buf[32];
    if(gethostname(buf,sizeof buf)==-1)
    {
        printf("Get host name error!\n");
        return -1;
    }
    printf("Now\nhostname = '%s'\n",buf);
}
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
int main()
{
    char buf[32];
    if(syscall(SYS_gethostname,buf,sizeof buf)==-1)
    {
        printf("Get host name error!\n");
        return -1;
    }
    printf("Now\nhostname = '%s'\n",buf);
}
