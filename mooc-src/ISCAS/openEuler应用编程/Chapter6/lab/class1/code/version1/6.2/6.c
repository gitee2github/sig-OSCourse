#include <stdio.h>
int main (int argc, char* argv[])
{
   int ret;
   char* filename = argv[1];
   FILE *fp = fopen(filename, "r");
   if(fp == NULL)
   {
		printf("ERROR: Cannot find file %s.\n", filename);
 		return 0;
   }

   ret = remove(filename);
   if(ret == 0) 
   {
      printf("File %s deleted successfully\n", filename);
   }
   else 
   {
      printf("ERROR: unable to delete the file %s.\n", filename);
   }
   return(0);
}
