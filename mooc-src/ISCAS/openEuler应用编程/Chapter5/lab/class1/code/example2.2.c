#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void){
	int i=0;
	int data = 0;
	pid_t pid ;
	int choose = 0;
	while((choose = getchar ()) != 'q'){
		switch(choose){
		case '1' :
			pid = fork();
			break;
		case '2':
			pid = vfork();
			break;
		default :
			//printf("aaa");
			break;
		}
		if(pid<0){
			printf("Error !\n");
		}
		if(pid == 0){
			data++;
			exit(0);
		}
		printf("process ID:%d\n",getpid());
		//printf("%d",i++);
		wait(pid);
		if(pid > 0){
			//printf("process ID:%d",getpid());
			printf("data is %d\n", data);
		}
	}
}
