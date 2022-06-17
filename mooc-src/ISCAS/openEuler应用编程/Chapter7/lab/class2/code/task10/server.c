#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <unistd.h>

#include <sys/time.h>

#include <string.h>

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

int net_conn(int sock_type, char *ip_addr, int port, int max_connect)
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

    ret = bind(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if_error(ret, "bind");

    /* TCP  listen */
    if (sock_type == TCP) {
        ret = listen(sock_fd, max_connect);
        if_error(ret, "listen");
    }

    return sock_fd;
}

int Accept(int sock_fd, struct sockaddr_in *cli_addr, socklen_t *cli_len)
{
    int acc_fd;
    acc_fd = accept(sock_fd, (struct sockaddr*)cli_addr, cli_len);
    if_error(acc_fd, "accept");
    return acc_fd;
}

pid_t Fork()
{
    pid_t chi_pid = fork();
    if_error(chi_pid, "fork");
    return chi_pid;
}

void set_msg(struct msg* m, int type, int len, char *data)
{
    m->type = type;
    m->data_len = len;
    memcpy(m->data, data, len);
}

int main(int argc, char **argv)
{
    int sock_fd, acc_fd, fd, n, tim;
    pid_t chi_pid;
    int cnt = 1;
    struct sockaddr_in cli_addr;
    socklen_t cli_len;
    char buf[MAXBUF+1], buff[MAXBUF+1];
    struct msg *rm, *sm;
    char filename[80];
    char recv_filename[80];

    rm = (struct msg*)malloc(MSG_SIZE);
    sm = (struct msg*)malloc(MSG_SIZE);
    /* net bind & accept */
    sock_fd = net_conn(TCP, NULL, 6666, 10);
    while (1) {
        acc_fd = Accept(sock_fd, &cli_addr, &cli_len);
        chi_pid = Fork();

        if (chi_pid == 0) {
        /* child process */
            recv(acc_fd, rm, MSG_SIZE, 0);
            if (rm->type != MSG_FILENAME) sys_err("MSG_FILENAME");
            sprintf(recv_filename, "file%d", getpid());
            fd = open(recv_filename, O_WRONLY | O_CREAT, 0777);
            if_error(fd, "open");
            while (1) {
                n = recv(acc_fd, rm, MSG_SIZE, 0);
                if (n <= 0) break;
                /* recv error or done msg */
                if (rm->type==MSG_EXCEPTION || rm->type==MSG_DONE) {
                    printf("child pid: %d\n", getpid());
                    printf("%s\n", rm->data);
                    break;
                }
                if (rm->type != MSG_CONTENT) sys_err("MSG_CONTENT");
                write(fd, rm->data, rm->data_len);
            }
            close(fd);
            close(sock_fd);
            exit(0);
        }
    }
    return 0;
}
