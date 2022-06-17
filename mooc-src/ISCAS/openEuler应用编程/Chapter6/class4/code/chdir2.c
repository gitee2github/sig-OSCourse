#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void main()
{

    char buf[30];
    char *cwd = NULL;
    FILE *fp = fopen("test.txt","r");
    fscanf(fp,"%s",buf); //read file text
    printf("text in test.txt is %s\n",buf);
    fclose(fp);
    char *path = "/home";
    chdir(path);
    cwd = getcwd(NULL,0);
    printf("current working directory:%s\n",cwd);
    fp = fopen("test.txt","r");
    if(fp !=NULL)
    {
     memset(buf,0,sizeof(buf));
     fscanf(fp,"%s",buf); //read file text
     printf("current text in test.txt is %s\n",buf);
    fclose(fp);
    }
    free(cwd);
}

