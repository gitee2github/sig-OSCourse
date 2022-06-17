#include <stdio.h>
#include <stdlib.h>
#define N 10

void quick_sort(int num[],int head,int tail);
int main()
{
    int i;
    int number[N];
    FILE *fp;
    if((fp = fopen("./result.txt","r"))==NULL) {
        printf("can't open.\n");
        exit(0);
    }
    for(i=0; i<N; i++) {
        fscanf(fp,"%d,",&number[i]);
    }
    fclose(fp);
    quick_sort(number,0,N-1);
    fp = fopen("./result.txt","w");
    for(i=0; i<N; i++) {
        fprintf(fp,"%d,",number[i]);
    }
}

void quick_sort(int num[],int head,int tail)
{
    int key=0,t,i,j;
    if(head<tail)
    {
        i=head;
        j=tail;
        while(i<j)
        {
            while(i<j&&num[i]<num[j])
                j--;
            if(i<j) {
                t=num[i];
                num[i]=num[j];
                num[j]=t;
                i++;
            }
            while(i<j&&num[i]<num[j])
                i++;
            if(i<j) {
                t=num[i];
                num[i]=num[j];
                num[j]=t;
                j--;
            }
            key=i;
            quick_sort(num,head,key-1);
            quick_sort(num,key+1,tail);
        }
    }
}


