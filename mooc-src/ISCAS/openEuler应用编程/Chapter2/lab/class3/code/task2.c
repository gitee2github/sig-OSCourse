#include <stdio.h>
void printStar() {
    int i,j;
    int count = 0;
    printf("\n");
    for(i=0; i<6; i++) {
        for(j=0; j<11; j++) {
            if((i>j) || (10-j)<i) {
                printf(" ");
            } else {
                fflush(stdout);
                printf("*");
                count++;
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    printStar();

    return 0;
}
