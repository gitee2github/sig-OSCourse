#include <stdio.h>

int main()
{
    int i=0;
    while(1)
    {
        printf("%d\n",i);
        system("date");
        i++;
        sleep(2);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int i=0;
	char *a ="";
	if(argc==2)
		a=argv[1];
	else
	{
		printf("Your input is wrong!\n");
		return 0;
	}
	while(1)
	{
		printf("%d\n",i);
		system(a);
		i++;
		sleep(2);
	}
	return 0;
}
