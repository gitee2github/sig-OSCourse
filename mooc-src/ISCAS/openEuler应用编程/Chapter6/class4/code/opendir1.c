#include <stdio.h>
#include <dirent.h>
int main()
{
    char* path = "/home/ruby/test";
    DIR *dirptr = opendir(path);
    struct dirent *entry;
    if(dirptr != NULL)
    {
        while (entry = readdir(dirptr))
        {  
            if(entry->d_type & DT_DIR)
		{ //do something 
                   printf("%s\n", entry->d_name);
	        }    
        } 
            closedir(dirptr);
    }
    return 0;
}
