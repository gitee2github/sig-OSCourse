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
    sprintf(buf,"v1-ThinkPad-T420");
    if(sethostname(buf,strlen(buf))<0)
    {
        printf("Set host name error!\n");
        return -1;
    }
    if(gethostname(buf,sizeof buf)==-1)
    {
        printf("Get host name error!\n");
        return -1;
    }
    printf("After\nhostname = '%s'\n",buf);
    return 0;
}
