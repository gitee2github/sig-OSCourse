#include <string.h>
#include <stdio.h>
#include <dirent.h>
int find_file_in_dir (const char *path, const char *file)
{
   struct dirent *entry;
   DIR *dir;
   int ret = 1;
   dir = opendir (path);
   if (dir == NULL)
   {
      return 1;
   }
   printf("I want to find file:%s\n",file);
   while (entry = readdir (dir))
   {
      
         if (strcmp (entry->d_name, file) == 0)
     	  {
	    ret = 0;
	    printf("fine the file:%s\n",entry->d_name);
	    break;
	  } 
   }
   closedir (dir);
   return ret;	
}

int main()
{
	char *path = "/home/ruby/test/chapt6/6-3";
	char *file = "test.txt";
	return find_file_in_dir(path,file);	
}
