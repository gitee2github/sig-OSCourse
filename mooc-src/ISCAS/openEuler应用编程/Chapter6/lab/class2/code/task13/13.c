#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
char expStr[100];
void scanDirfiles(char*path)
{
    struct dirent*file;
    DIR*d;
    char fullpath[500];
    d=opendir(path);
    if(d==NULL)
    {
        perror("opendir error");
        exit(1);
    }
    while(file=readdir(d)){
        if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
               continue;
        if(file->d_type==DT_DIR){
            sprintf(fullpath,"%s/%s",path,file->d_name);
            scanDirfiles(fullpath);
        }else{
            if(strstr(file->d_name,expStr)!=NULL)
                printf("%s/%s\n",path,file->d_name);
        }
    }
    closedir(d);
}
int main(int argc,char*argv[])
{
    if(argc<=2){
        printf("error:please input dir and expStr!\n");
        exit(1);
    }
    char path[256];
    int len;
    if(chdir(argv[1])==-1)
    {
        perror("arg");
        exit(1);
    }
    getcwd(path,255);
    len=strlen(argv[2]);
    strncpy(expStr,argv[2],len);
    expStr[len]=0;
    scanDirfiles(path);
    return 0;
}
