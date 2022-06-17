#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int accmode, val;
    if(argc != 2){
        printf("the argc must equel to 2");
        return 1;
    }
    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0){
        perror("fcntl");
        exit(EXIT_FAILURE);
    }
    accmode = val & O_ACCMODE;
    if(accmode == O_RDONLY)
        printf("read only\n");
    else if (accmode == O_WRONLY)
        printf("write only\n");
    else if (accmode == O_RDWR)
        printf("read write\n");
    else
        printf("unknown mode\n");

    if(val & O_APPEND)//当读写文件时会从文件尾开始移动，也就是所写入的数据会以附加的方式加入到文件后面
        printf(", append");
    if(val & O_NONBLOCK)//以不可阻断方式打开，也就是无论有无数据读取或等待，都会立即返回进程之中
        printf(", nonblocking");
    return 0;
}
