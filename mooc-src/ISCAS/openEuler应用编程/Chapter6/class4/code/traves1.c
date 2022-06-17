#include <string.h>
#include <stdio.h>
#include <dirent.h>

int find_file_in_dir (const char *path)
{
   struct dirent *entry;
   DIR *dir;
   dir = opendir (path);
   while (entry = readdir (dir))
   {
       char* name = entry->d_name;
       int len = strlen(name);    // 头文件<string.h>
       if(name[len-1] == 'c' && name[len-2] == '.' ) {
           char fullname[100];
           sprintf(fullname, "%s/%s", path, name);
           printf("%s\n", fullname);
       }
   }
   closedir (dir);
   return 0;	
}

int main()
{
	char *path = "/home/ruby/test/chapt6/6-3";
	find_file_in_dir(path);
	return 0;
}
