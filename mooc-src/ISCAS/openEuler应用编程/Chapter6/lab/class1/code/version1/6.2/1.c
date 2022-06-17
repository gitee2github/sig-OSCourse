#include <stdio.h>
int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("ERROR: Please input the file name.\n");
		return 0;
	}
	
	char* filename = argv[1];
	FILE* fp = fopen(filename, "w+");
	if(fp == NULL)
	{
		printf("ERROR: Open file %s failed.\n", filename);
		return 0;
	}
	else
	{
		printf("Open file %s successfully.\n", filename);	
	}

	fclose(fp);
	return 0;
}
