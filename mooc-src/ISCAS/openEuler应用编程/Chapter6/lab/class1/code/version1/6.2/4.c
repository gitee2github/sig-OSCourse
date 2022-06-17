#include <stdio.h>

int main (int argc, char* argv[])
{
   if(argc < 3)
   {
      printf("ERROR: Invalid argument number.\n");
      return 0;
   }
   FILE *fp;
   char* oldname = argv[1];
   char* newname = argv[2];
   fp = fopen( oldname , "r" );
   if(fp == NULL)
   {
      printf("ERROR: Cannot find file: %s.\n", oldname);
      return 0;
   }
   int ret;
   if(ret = rename(oldname, newname) != 0)
   {
		printf("ERROR: Rename file %s failed.\n", oldname);
		return 0;
   } 
   else
   {
		printf("Rename file %s to %s successfully.\n", oldname, newname);
   }
   fclose(fp);
   return(0);
}
