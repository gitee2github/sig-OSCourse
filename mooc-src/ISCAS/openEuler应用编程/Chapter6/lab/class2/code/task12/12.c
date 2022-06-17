#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>
#define SIZE 10000
int rmfile(char *pathname,char *filename)
{
    struct stat st;
    struct dirent *entry;
    DIR *dirptr=NULL;
    char buffer[SIZE];
    int i=strlen(pathname);
    int j=strlen(filename);
    pathname[i-1]='\0';
    filename[j-1]='\0';
    if(pathname[i-2]=='/')
        sprintf(buffer,"%s%s",pathname,filename);
    else
        sprintf(buffer,"%s/%s",pathname,filename);
    printf("%s\n",buffer);
    int is_exist=0;
    if((dirptr=opendir(pathname))==NULL){
        printf("open dir error\n");
        return 1;
    }
    else{
        while(entry=readdir(dirptr)){
            char tmp[SIZE];
            if(strcmp(entry->d_name,".")==0||strcmp(entry->d_name,"..")==0)
                continue;
            sprintf(tmp,"%s/%s",pathname,entry->d_name);
            stat(tmp,&st);
            if(S_ISREG(st.st_mode)){
                if(strcmp(filename,entry->d_name)==0){
                    is_exist=1;
                    unlink(tmp);
                    printf("Remove successfully!\n");
                    break;
                }
            }
        }
        if(!is_exist)
            printf("%s is not exist or a regular file.\n",filename);
    }
    return 0;
}

int main()
{
    char pathname[SIZE];
    char filename[SIZE];
    printf("please input a pathname:\n");
    fgets(pathname,SIZE,stdin);
    printf("please input a filename:\n");
    fgets(filename,SIZE,stdin);
    rmfile(pathname,filename);
    return 0;
}
