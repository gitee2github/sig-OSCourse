#include <stdio.h>

int getint()
{
    int tem;
    char s[8];
    fgets(s,8,stdin);
    if(tem=atoi(s))
        return tem;
}

int main()
{
    int x,y;
    while(1)
    {
        printf("########################\n");
        printf("input x:\n");
        x=getint();
        while(x==0)
        {
            printf("input error!\n");
            printf("input x:\n");
            x=getint();
        }
        printf("input y:\n");
        y=getint();
        while(y==0)
        {
            printf("input error!\n");
            printf("input y:\n");
            y=getint();
        }
        printf("x+y=%d\n",x+y);
    }
    return 0;
}
