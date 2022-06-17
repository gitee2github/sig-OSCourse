#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
char *str = "task3.c";
void std_fileno()
{
    printf("stdin is : %d\n",fileno(stdin));
    printf("stdout is : %d\n",fileno(stdout));
    printf("stderr is : %d\n",fileno(stderr));
}
void file_fileno( int* fp )
{
    if( ( *fp = open(str, O_WRONLY)) == -1 ) {
        perror("open");
        exit(EXIT_FAILURE);
    }
}
int main()
{
    int fp1,fp2;
    std_fileno();
    printf("---------------------\n");
    printf("open file and open again BEFORE it closed\n");
    file_fileno(&fp1);
    printf("%s is : %d\n",str,fp1);
    file_fileno(&fp2);
    printf("%s is : %d\n",str,fp2);
    printf("---------------------\n");
    close(fp1);
    close(fp2);
    printf("---------------------\n");
    printf("open file and open again AFTER it closed\n");
    file_fileno(&fp1);
    printf("%s is : %d\n",str,fp1);
    close(fp1);
    file_fileno(&fp2);
    printf("%s is : %d\n",str,fp2);
    printf("---------------------\n");
    close(fp2);
    return 0;
}
