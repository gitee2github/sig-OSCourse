#include"stdio.h"

int main() {
        int count = 1;
        int child;

        if(!(child = fork())) {
                int i;
                for(i = 0; i < 20; i++) {
			sleep(1);
                        printf("This is son, his count is: %d. and his pid is: %d\n", i, getpid());
                }
		exit(0);
        } else {
		sleep(3);
                printf("This is father, his count is: %d, his pid is: %d\n", count, getpid());
        }
}
