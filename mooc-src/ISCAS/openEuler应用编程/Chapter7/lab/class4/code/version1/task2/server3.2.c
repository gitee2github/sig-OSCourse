/*
 * 实训3 子任务2
 * Server
 *
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 2048
#define BACKLOG 64

void print_usage()
{
    printf("usage:\n"
           "\tserver {listen_port} {file_path}\n");
}

int main(int argc, char *argv[])
{
    char buf[BUFSIZE];
    char *ip,*port,*file_path;
    FILE *file;
    struct sockaddr_in server_addr, client_addr;
    int listensock,clientsock;
    int ret=0;
    int addrlen;
    int datalen;

    if(argc<3) {
        print_usage();
        return -1;
    }

    port=argv[1];
    file_path=argv[2];

    file=fopen(file_path,"w");
    if(file==NULL) {
        printf("fopen error=%d\n",errno);
        return -6;
    }

    memset(&server_addr,0,sizeof(struct sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=INADDR_ANY ;
    server_addr.sin_port=htons(atoi(port));

    listensock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(listensock<0) {
        printf("socket create error=%d\n",errno);
        ret=-2;
        goto exit2;
    }

    if(bind(listensock,(struct sockaddr*)&server_addr,sizeof(struct sockaddr_in))<0) {
        printf("bind error=%d\n",errno);
        ret=-3;
        goto exit;
    }

    if(listen(listensock,BACKLOG)<0) {
        printf("listen error=%d\n",errno);
        ret=-4;
        goto exit;
    }

    addrlen=sizeof(struct sockaddr_in);
    clientsock=accept(listensock,(struct sockaddr*)&client_addr,&addrlen);
    if(clientsock<0) {
        printf("accept error=%d\n",errno);
        ret=-5;
        goto exit;
    }

    printf("--%s:%d--\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

    while (1) {
        datalen=recv(clientsock,buf,BUFSIZE,0);
        if(datalen>0) {
            fwrite(buf,1,datalen,file);
        } else {
            if(datalen<0) {
                printf("recv error\n");
            }
            break;
        }
    }
    close(clientsock);

exit:
    close(listensock);

exit2:
    fclose(file);
    return ret;
}
