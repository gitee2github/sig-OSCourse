#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#define BLKSIZE 2048
#define BUFSIZE 2056
#define MSG_FILENAME    1
#define MSG_CONTENT     2
#define MSG_ACK         3
#define MSG_DONE        4
#define MSG_EXCEPTION   5
struct msg {
    int32_t type;
    int32_t data_len;
    char data[];
};
void print_usage()
{
    printf("usage:\n"
            "\tclient {server_ip} {server_port} {file_path}\n");
}
int main(int argc, char *argv[])
{
    char buf[BUFSIZE];
    struct msg *m;
    char *ip,*port,*file_path,*file_name,*tmp;
    FILE *file;
    int clientsock;
    struct sockaddr_in server_addr;
    int ret=0;
    int datalen;
    int msglen;
    time_t start_time,end_time;
    if(argc<4) {
        print_usage();
        return -1;
    }
    ip=argv[1];
    port=argv[2];
    file_path=argv[3];//文件完整路径
    //从文件完整路径中截取文件名
    tmp=strrchr(file_path,'/');
    file_name=tmp?(tmp+1):file_path;
    file=fopen(file_path,"r");
    if(file==NULL) {
        printf("fopen error=%d\n",errno);
        return -5;
    }
    memset(&server_addr,0,sizeof(struct sockaddr_in));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=inet_addr(ip);
    server_addr.sin_port=htons(atoi(port));
    clientsock=socket(AF_INET,SOCK_STREAM,0);
    if(clientsock<0) {
        printf("socket create error=%d\n",errno);
        ret=-2;
        goto exit2;
    }
    if(connect(clientsock,(struct sockaddr*)&server_addr,sizeof(struct sockaddr_in))<0) {
        printf("connect error=%d\n",errno);
        ret=-3;
        goto exit1;
    }
    start_time=time(NULL);//开始时间
    //创建并发送MSG_FILENAME
    m=(struct msg*)buf;
    m->type=MSG_FILENAME;
    m->data_len=strlen(file_name);
    memcpy(m->data,file_name,m->data_len);
    msglen=sizeof(struct msg)+m->data_len;
    if(send(clientsock,buf,msglen,0)<0) {
        printf("send MSG_FILENAME error=%d\n",errno);
        ret=-4;
        goto exit1;
    }
    //创建并发送MSG_CONTENT
    m=(struct msg*)buf;
    m->type=MSG_CONTENT;
    while (1) {
        //读文件
        datalen=fread(m->data,1,BLKSIZE,file);
        if(datalen<=0) {
            if(feof(file)) {//文件结束
                printf("send MSG_DONE\n");
                m->type=MSG_DONE;
                m->data_len=0;
                //发送MSG_DONE
                if(send(clientsock,buf,sizeof(struct msg),0)<0) {
                    printf("send MSG_DONE error=%d\n",errno);
                    ret=-5;
                }
            } else if(ferror(file)) {//读文件错误
                printf("fread error=%d\n",errno);
                ret=-6;
                m->type=MSG_EXCEPTION;
                m->data_len=0;
                //发送MSG_EXCEPTION
                if(send(clientsock,buf,sizeof(struct msg),0)<0) {
                    printf("send MSG_EXCEPTION error=%d\n",errno);
                    ret=-7;
                }
            }
            goto exit0;
        }
        m->data_len=datalen;
        msglen=sizeof(struct msg)+m->data_len;
        //发送消息
        if(send(clientsock,buf,msglen,0)<0) {
            printf("send MSG_CONTENT error=%d\n",errno);
            ret=-4;
            goto exit1;
        }
        else
        {
            printf("send msg_content\n");
            printf("msg type is %d\n",m->type);
        }
    }
exit0:
    end_time=time(NULL);//结束时间
    printf("Use time: %ld s\n",end_time-start_time);

exit1:
    close(clientsock);

exit2:
    fclose(file);
    return ret;
}
