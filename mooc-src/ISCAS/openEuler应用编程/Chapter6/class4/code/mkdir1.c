#include <sys/stat.h>
int main()
{
    mkdir("./test_mkdir", S_IRUSR|S_IWUSR |S_IRGRP);
    //mkdir(“./test_mkdir”, 0777);   // 不要写成777
    return 0;
}
