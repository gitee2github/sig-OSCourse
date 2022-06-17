#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    long long size = 0;
    void *p = NULL;
    unsigned chunk_size = 1024 * 1024 * 16;
    while(1) {

        if ((p = (void*) malloc(chunk_size)) == NULL) {
            printf("out of memory!!!\n");
            break;
        }
        memset(p, 1, chunk_size);
        size += chunk_size;
        printf("[%u] - memory is allocated [%lld] bytes \n", getpid(), size);
        sleep(1);
    }
    return 0;
}
