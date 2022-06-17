#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
void rprintFileName(DIR *dir,char*pathname)
{
	struct dirent*en;
	struct stat st;
	char buffer[10000];
	if(pathname[strlen(pathname)-1]=='/')
		pathname[strlen(pathname)-1]='\0';
	time_t curtime=time(NULL);
	time_t pastonehour=curtime-3600;
	while((en=readdir(dir))!=NULL){
		if(strcmp(en->d_name,".")==0||strcmp(en->d_name,"..")==0)
			continue;
		sprintf(buffer,"%s/%s",pathname,en->d_name);
		stat(buffer,&st);
		time_t mtime=st.st_mtime;
		if(S_ISDIR(st.st_mode)){
			DIR*endir=opendir(buffer);
			rprintFileName(endir,buffer);
		}
		else{	
			if(mtime>pastonehour)
				printf("%s\n",buffer);	
		}
	}
}
int main(int argc,char*argv[])
{
	DIR* dir=opendir(argv[1]);
	rprintFileName(dir,argv[1]);
	return 0;
}
