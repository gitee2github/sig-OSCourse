#include <unistd.h>
#include <sys/types.h>
int main()
{
	pid_t pid;
	if((pid=fork())==-1)
		printf("fork error");
	else if(pid == 0)
	{
		printf("b\n");
	}
	else
	{
		printf("a\n");
		if((pid=fork())==-1)
			printf("fork error");
		else if(pid == 0)
		{
			printf("c\n");
		}
	}
}

		



