#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Now:\n");
    printf("%s\n",getenv("WELCOME"));
    if(0!=setenv("WELCOME","Hello",1))
    {
        printf("setenv error!!\n");
        return -1;
    }
    printf("After:\n");
    printf("%s\n",getenv("WELCOME"));
}
