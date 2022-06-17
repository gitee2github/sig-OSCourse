#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#define SIZE 10000
int main(void)
{
    DIR*dirptr1,*dirptr2;
    struct stat st;
    struct dirent *entry1,*entry2;
    char pathname[SIZE];
    char dirname[SIZE];
    printf("please input a file pathname:\n");
    fgets(pathname,SIZE,stdin);
    printf("please input a dirname:\n");
    fgets(dirname,SIZE,stdin);
    int i=strlen(pathname);
    pathname[i-1]='\0';
    int j=strlen(dirname);
    dirname[j-1]='\0';
    int flag1=0;
    int flag2=0;
    if((dirptr1=opendir(pathname))==NULL){
        printf("open die error!\n");
        return 1;
    }
    else{
        while(entry1=readdir(dirptr1)){
            if((strcmp(entry1->d_name,"."))==0||strcmp(entry1->d_name,"..")==0)
                continue;
            char tmp[SIZE];
            if(pathname[i-2]=='/')
                sprintf(tmp,"%s%s",pathname,entry1->d_name);
            else
                sprintf(tmp,"%s/%s",pathname,entry1->d_name);
            if(stat(tmp,&st)!=0)
                continue;
            if(S_ISDIR(st.st_mode)){
                if(strcmp(entry1->d_name,dirname)==0){
                    flag1=1;	
                    dirptr2=opendir(tmp);
                    while((entry2=readdir(dirptr2))!=NULL){
                        if(strcmp(entry2->d_name,".")==0||strcmp(entry2->d_name,"..")==0)
                            continue;
                        flag2=1;
                    }
                    if(flag2==0){
                        printf("This dir is null dir\n");
                        if(rmdir(tmp)==-1)
                            perror("failed to rmdir!\n");
                        else
                            printf("successed to rmdir!\n");
                    }
                    else{
                        printf("This dir is not null dir\n");
                        printf("%s\n",entry1->d_name);
                        return 1;
                    }
                    closedir(dirptr2);
                }
            }
        }
        if(flag1==0)	
            printf("This dir is not exist!\n");
        closedir(dirptr1);
    }
    return 0;
}
