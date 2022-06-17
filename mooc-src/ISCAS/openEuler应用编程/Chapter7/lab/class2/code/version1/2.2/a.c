#include <stdio.h>
#include <string.h>
int main()
{
    char str[5];
    memset(str,0,sizeof(str));
    int rt = snprintf(str,3,"%s","abcdefg");
    printf("%d\n",rt);
    printf("%s\n",str);
    return 0;
}
