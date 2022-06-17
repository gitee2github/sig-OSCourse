#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[])
{
   if(argc < 2)
   {
      printf("ERROR: Invalid argument number.\n");
      return 0;
   }
   FILE *fp;
   char* filename = argv[1];
   fp = fopen( filename , "r" );
   if(fp == NULL)
   {
      printf("ERROR: Cannot open file: %s.\n", filename);
      return 0;
   }

   char str[1000]; 
   int i = 0;
   for(;i < 1000; i++)
	str[i] = '\0';
   fread(str, sizeof(char), 1000, fp);
   printf("Text in file %s is:\n%s\n", filename, str);
   fclose(fp);
   return(0);
}
