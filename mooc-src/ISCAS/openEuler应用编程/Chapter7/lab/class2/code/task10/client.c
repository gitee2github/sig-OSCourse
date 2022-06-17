#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/time.h>

#include <strings.h>

#define TCP SOCK_STREAM
#define UDP SOCK_DGRAM

#define MAXLINE 80
#define MAXBUF 1024

#define MSG_SIZE 4096

#define MSG_FILENAME 1
#define MSG_CONTENT 2
#define MSG_ACK 3
#define MSG_DONE 4
#define MSG_EXCEPTION 5

struct msg
{
    int type;
    int data_len;
    char data[0];
};

void if_error(int status_code, char *err_msg)
{
    if (status_code < 0) {
        perror(err_msg);
        exit(errno);
    }
}

void sys_err(char *err_msg)
{
    printf("error: ");
    printf("%s", err_msg);
    exit(-1);
}

int net_conn(int sock_type, char *ip_addr, int port)
{
    struct sockaddr_in server_addr;
    int sock_fd, ret;

    /* socket */
    sock_fd = socket(AF_INET, sock_type, 0);
    if_error(sock_fd, "socket");

    /* bind */
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = (NULL == ip_addr ? INADDR_ANY : inet_addr(ip_addr));

    ret = connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if_error(ret, "connect");

    return sock_fd;
}

void set_msg(struct msg* m, int type, int len, char *data)
{
    m->type = type;
    m->data_len = len;
    memcpy(m->data, data, len);
}

int main(int argc, char **argv)
{
    int sock_fd, fd, n, tim;
    char buf[MAXBUF+1];
    struct msg *sm, *rm;
    char filename[80];
    char msg_done[] = "send file done!";
    char err_msg[] = "send file error!";
    struct timeval tv_start, tv_finish;

    sm = (struct msg*)malloc(MSG_SIZE);
    rm = (struct msg*)malloc(MSG_SIZE);

    if (argc != 2) return -1;

    /* connect to server */
    sock_fd = net_conn(TCP, "127.0.0.1", 6666);

    gettimeofday(&tv_start, NULL);

    /* send file name */
    strcpy(filename, argv[1]);

    set_msg(sm, MSG_FILENAME, strlen(filename), filename);
    send(sock_fd, sm, MSG_SIZE, 0);


    fd = open(filename, O_RDONLY, 0777);
    /* if open file error */
    if (fd < 0) {
        set_msg(sm, MSG_EXCEPTION, sizeof(err_msg), err_msg);
        send(sock_fd, sm, MSG_SIZE, 0);
        exit(-1);
    }

    while (1) {
        n = read(fd, buf, MAXBUF);
        if (n <= 0) break;
        /* send file content */
        set_msg(sm, MSG_CONTENT, n, buf);
        send(sock_fd, sm, MSG_SIZE, 0);
    }
    close(fd);
    /* send done msg */
    set_msg(sm, MSG_DONE, sizeof(msg_done), msg_done);
    send(sock_fd, sm, MSG_SIZE, 0);

    /* print time info */
    gettimeofday(&tv_finish, NULL);
    tim = (tv_finish.tv_sec-tv_start.tv_sec)*1000+tv_finish.tv_usec-tv_start.tv_usec;
    printf("send file time is %d ms\n", tim);
    close(sock_fd);
    return 0;
}
