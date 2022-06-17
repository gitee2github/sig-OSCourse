/*
 * ʵѵ3 ������4
 * Server
 *
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BACKLOG 64
#define BLKSIZE 2048
#define BUFSIZE 2056

#define MSG_FILENAME	1
#define MSG_CONTENT		2
#define MSG_ACK			3
#define MSG_DONE		4
#define MSG_EXCEPTION	5

struct msg {
    int32_t type;
    int32_t data_len;
    char data[];
};

void print_usage()
{
    printf("usage:\n"
           "\tserver {listen_port}\n");
}

int main(int argc, char *argv[])
{
    char buf[BUFSIZE],buf2[BUFSIZE],file_path[256];
    struct msg *m;
    char *ip,*port;
    FILE *file=NULL;
    struct sockaddr_in server_addr, client_addr;
    int listensock,clientsock;
    int ret=0;
    int addrlen;
    int msglen;

    if(argc<2) {
        print_usage();
        return -1;
    }

    port=argv[1];
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
        goto exit1;
    }

    if(listen(listensock,BACKLOG)<0) {
        printf("listen error=%d\n",errno);
        ret=-4;
        goto exit1;
    }

	addrlen=sizeof(struct sockaddr_in);
    clientsock=accept(listensock,(struct sockaddr*)&client_addr,&addrlen);
    if(clientsock<0) {
        printf("accept error=%d\n",errno);
        ret=-5;
        goto exit1;
    }

    printf("--%s:%d--\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

    //����MSG_ACK��Ϣ
    m=(struct msg*)buf2;
    m->type=MSG_ACK;
    m->data_len=0;

    m=(struct msg*)buf;
    while (1) {
        //������Ϣ
        msglen=recv(clientsock,buf,BUFSIZE,0);

        //�ظ�MSG_ACK
        send(clientsock,buf2,sizeof(struct msg),0);

        //������Ϣ

        if(msglen<=0) {
            printf("recv error\n");
            goto exit0;
        }

        if(m->type==MSG_FILENAME) {
            //��ȡ�ļ���
            memcpy(file_path,m->data,m->data_len);
            file_path[m->data_len]=0;
            //���ļ�
            file=fopen(file_path,"w");
            if(file==NULL) {
                printf("fopen error=%d\n",errno);
                ret=-6;
                goto exit0;
            }
        } else if(m->type==MSG_CONTENT) {
            fwrite(m->data,1,m->data_len,file);
        } else if(m->type==MSG_DONE) {
            printf("MSG_DONE\n");
            goto exit0;
        } else if(m->type==MSG_EXCEPTION) {
            printf("MSG_EXCEPTION\n");
            goto exit0;
        }
    }
exit0:
    fclose(file);
    close(clientsock);

exit1:
    close(listensock);

exit2:
    return ret;
}
