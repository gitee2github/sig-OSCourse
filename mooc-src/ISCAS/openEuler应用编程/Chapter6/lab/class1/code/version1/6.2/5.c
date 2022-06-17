#include <stdio.h>

int main (int argc, char* argv[])
{
   if(argc < 2)
   {
      printf("ERROR: Invalid argument number.\n");
      return 0;
   }
   FILE *fpold, *fpnew;
   char* oldname = argv[1];
   char* newname = argv[2];
   fpold = fopen( oldname , "r" );
   fpnew = fopen( newname, "w");
   if(fpold == NULL)
   {
      printf("ERROR: Cannot open file: %s.\n", oldname);
      return 0;
   }
   if(fpnew == NULL)
   {
      printf("ERROR: Cannot open file: %s.\n", newname);
      return 0;
   }

   char str[100];
   int i = 0;
   for(;i < 100; i++)
	str[i] = '\0';
   int len = fread(str, sizeof(char), 100, fpold);
   fwrite(str, sizeof(char), len, fpnew);	
   fclose(fpold);
   fclose(fpnew);
   return(0);
}
