#include <sys/stat.h>
int main()
{
    umask(0);
    mkdir("./test_mkdir2",0777);  
    return 0;
}
