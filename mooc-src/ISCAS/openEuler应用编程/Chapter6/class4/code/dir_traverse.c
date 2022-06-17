#include <string.h>
#include <stdio.h>
#include <dirent.h>

int dir_traverse (const char *path)
{
    DIR *dir;
    dir = opendir(path);
    if (dir == NULL) 
    {
        return -1;
    }
    struct dirent *entry;
    char fullpath[200];
    while((entry = readdir(dir)) != NULL) 
	{
        if((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0)) 
		{
            continue; //忽略.和..两个特殊目录
        } 
        sprintf(fullpath, "%s/%s", path, entry->d_name); //获取绝对路径
        printf("%s\n", fullpath);
        if(entry->d_type & DT_DIR) //若当前项是目录，则递归遍历此目录
            dir_traverse(fullpath);
    }
    closedir(dir);
    return 0;
}

int main()
{
   char* path = "/home/ruby/test/chapt6";
   if(!dir_traverse(path))
	printf("Success.\n");
   else
	printf("Fail.\n");

   return 0;
}
