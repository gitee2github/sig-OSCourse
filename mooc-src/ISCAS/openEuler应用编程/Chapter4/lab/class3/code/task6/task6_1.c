#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    struct stat stat_flag;
    if(chmod("test01", S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH) < 0) {
        printf("stat error\n");
        return 1;
    }
    if(chmod("test02",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH) < 0){
        printf("stat test02 error\n");
        return 1;
    }
    if(chmod("test03",S_IRUSR|S_IWUSR|S_IWGRP|S_IWOTH) < 0){
        printf("stat test03 error\n");
        return 1;
    }
    return 0;
}
