#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main( )
{
    int fd1=-1, fd2=-1, num;
    char *file1, *file2;
    char buf[1000];

    file1 = "/etc/passwd";
    file2 = "myfile";
    if( (fd1 = open(file1,O_RDONLY)) == -1 ) {
        printf("can't open the %s file",file1);
        return 1;
    }
    if( ((fd2=open(file2,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IWUSR|S_IRGRP|S_IROTH))) == -1 ) {
        printf("can't create the %s file",file2);
        return -1;
    }
    while( (num = read(fd1,buf,1000)) > 0 ){
        printf("%s",buf);
        if( write(fd2,buf,num) == -1){
            printf("can't write to %s file\n",file2);
            return -1;
        }
    }
    close(fd1);
    close(fd2);
    return 0;
}
//added copy half file to passwd_half
