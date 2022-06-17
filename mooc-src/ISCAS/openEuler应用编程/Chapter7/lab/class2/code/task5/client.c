#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define BUFSIZE 2048
void print_usage()
{
    printf("usage:\n\tclient {server_ip} {server_port} {file_path}\n");
}
int main(int argc,char*argv[])
{
    char buff[BUFSIZE];
    char*ip,*port,*file_path;
    FILE*file;
    struct sockaddr_in server_addr;
    int clientsock;
    int ret=0;
    int datalen;
    if(argc<4){
        print_usage();
        return -1;
    }
    ip=argv[1];
    port=argv[2];
    file_path=argv[3];
    file=fopen(file_path,"r");
    if(file==NULL){
        printf("fopen error=%d\n",errno);
        return -5;
    }
    memset(&server_addr,0,sizeof(struct sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr(ip);
    server_addr.sin_port=htons(atoi(port));
    clientsock=socket(AF_INET,SOCK_STREAM,0);
    if(clientsock<0){
        printf("socket create error=%d\n",errno);
        ret=-2;
    }
    if(connect(clientsock,(struct sockaddr*)&server_addr,sizeof(struct sockaddr_in))<0){
        printf("connect error=%d\n",errno);
        ret=-3;
        close(clientsock);
    }
    while(1){
        datalen=fread(buff,1,BUFSIZE,file);
        printf("datalen=%d\n",datalen);
        if(datalen<=0){
            if(feof(file))
                break;
            else if(ferror(file)){
                perror("ferror\n");
                close(clientsock);
                fclose(file);
                return 0;
            }
        }
        if(send(clientsock,buff,datalen,0)<0){
            close(clientsock);
            fclose(file);
            return 0;
        }
        sleep(10);
    }
    printf("send over\n");
    close(clientsock);
    fclose(file);
    return 0;
}
