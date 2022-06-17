/*
 *由消息队列实现的简单聊天室程序(server)
 *在服务器端主要实现广播功能，以及服务器退出以后通知
 *所有客户端退出并删除消息队列功能
 *对所有客户端的统计由链表实现
 * */
#include <stdio.h>

#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>

#include <stdlib.h>

#include <errno.h>

#include <string.h>

#include <unistd.h>

#include <sys/wait.h>

#include <signal.h>

#define TYPE_SRV 10
#define N 128
struct msgbuf {
  long mtype;
  int subtype;
  int pid;
  char nick_name[N];
  char mtext[N];
};
#define MSG_LEN(sizeof(struct msgbuf) - sizeof(long))
typedef struct _node_ {
  int data;
  struct _node_ * next;
}
listnode, * linklist;
//function declare
void Broadcast(linklist h, int msgid, struct msgbuf * msg);
linklist CreateLinklist(); //create linklist
int Length(linklist h); //get the linklist's length
int Empty(linklist h); //judge if the linklist is empty
int Insert(linklist h, int value);
void Delete(linklist h, int value);
int GetValue(linklist h, int pos);
int main(int argc, char * argv[]) {
  key_t key;
  int msgid;
  pid_t pid;
  struct msgbuf msg;
  //生成key
  if ((key = ftok("./", 's')) < 0) {
    perror("ftok error.");
    exit(-1);
  }
  //服务器进程创建创建消息队列
  if ((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
    perror("msgget error.");
    exit(-1);
  }
  //使用fork创建子进程
  if ((pid = fork()) < 0) {
    perror("error to fork.");
    exit(-1);
  } else if (pid == 0) { //子进程专门用来实现消息的转发功能
    //创建单链表
    linklist h;
    h = CreateLinklist();
    while (1) {
      if (msgrcv(msgid, & msg, MSG_LEN, TYPE_SRV, 0) < 0) {
        perror("msgrcv error.\n");
        exit(1);
      }
      //对接收到的子进程进行子类型判断
      switch (msg.subtype) {
      case 1: //register
        if (Insert(h, msg.pid) != 0) {
          printf("insert error.\n");
          exit(-1);
        }
        printf("[Name -%s- ID -%d- regist]\n", msg.nick_name, msg.pid);
        Broadcast(h, msgid, & msg);
        break;
      case 2: //broadcast 
        Broadcast(h, msgid, & msg);
        //若收到console来的quit要求，在广播完以后，自己退出(不然会出现无限循环)
        if (strncmp(msg.mtext, "quit", 4) == 0) {
          exit(0);
        }
        break;
      case 3: //unregister
        if (!Empty(h)) {
          Delete(h, msg.mtype);
        }

        printf("[Name -%s- ID -%d-off line.]\n", msg.nick_name, msg.pid);
        Broadcast(h, msgid, & msg);
        break;
      default:
        break;
      }
    }
  } else { //父进程用于服务器控制台
    msg.mtype = TYPE_SRV; //因为不知道有多少个客户端，发给服务器后再转发
    msg.subtype = 2;
    while (1) {
      printf("[server console]\n");
      fgets(msg.mtext, N, stdin);
      //控制台收到quit时，通知客户端，server quit.
      if (strncmp(msg.mtext, "quit", 4) == 0) {
        msgsnd(msgid, & msg, MSG_LEN, 0);
        sleep(2);
        msgctl(msgid, IPC_RMID, NULL); //删除消息队列
        kill(pid, SIGKILL);
        exit(0);
      }
    }
  }
  return 0;
}
void Broadcast(linklist h, int msgid, struct msgbuf * msg) {
  int i;
  for (i = 0; i < Length(h); i++) {
    msg -> mtype = GetValue(h, i);
    if (msg -> mtype != msg -> pid) {
      msgsnd(msgid, msg, MSG_LEN, 0);
    }
  }
}
linklist CreateLinklist() {
  linklist h;
  h = (linklist) malloc(sizeof(listnode));
  h -> next = NULL;

  return h;
}
//get the linklist's length
int Length(linklist h) {
  int n = 0;
  h = h -> next;
  while (h) {
    n++;
    h = h -> next;
  }
  return n;
}
//judge if the linklist is empty
int Empty(linklist h) {
  return (NULL == h -> next);
}
//insert the data whose value = 'value' at the end of the list
int Insert(linklist h, int value) {
  linklist p;
  p = (linklist) malloc(sizeof(listnode));
  p -> data = value;
  p -> next = NULL;
  while (h -> next) {
    h = h -> next;
  }

  h -> next = p;
  return 0;
}
//del a data by its value
void Delete(linklist h, int value) {
  linklist p = h -> next;
  //h points at the previous one,and p points at the later one
  while (p) {
    if (p -> data == value) {
      h -> next = p -> next;
      free(p);
      p = h -> next;
    } else {
      h = p;
      p = h -> next;
    }
  }
  return;
}
//get the data at the position of pos
int GetValue(linklist h, int pos) {
  h = h -> next;
  while (pos--) {
    h = h -> next;
  }
  return h -> data;
}
/*
 *用消息队列实现的简单聊天室程序(client)
 *实现的功能：
 *1。上线提醒
 *2。下线提醒 
 *3。服务器断线后子进程都退出
 * */
#include <stdio.h>

#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/msg.h>

#include <stdlib.h>

#include <errno.h>

#include <string.h>

#include <unistd.h>

#include <sys/wait.h>

#include <signal.h>

#define _DEBUG_
#define TYPE_SRV 10 //send 10是server的消息类
#define N 128
struct msgbuf {
  long mtype;
  int subtype; //1->register 2->broadcast 3->unregister
  int pid;
  char nick_name[N];
  char mtext[N];
};
//定义消息正文大小的宏
#define MSG_LEN(sizeof(struct msgbuf) - sizeof(long))
int main(int argc, char * argv[]) {
  key_t key;
  int msgid;
  pid_t pid;
  int TYPE_ME; //由getpid()来指定唯一该进程才有的mtype
  struct msgbuf msg;
  TYPE_ME = getpid(); //用自己进程的进程号作为自己收消息的消息类型
  //argv[1]用于接收昵称
  if (argc < 2) {
    printf("Usage:%s <nick_name>\n", argv[0]);
    exit(-1);
  }
  //生成消息队列的key
  if ((key = ftok("./", 's')) < 0) {
    perror("ftok error.");
    exit(-1);
  }

  //如果服务器已创建消息队列才可打开，客户端无权创建
  if ((msgid = msgget(key, 0666)) < 0) {
    printf("[server maybe not on line...]\n");
    exit(-1);
  }
  //每启动一个客户端要先实现一个注册操作
  msg.mtype = TYPE_SRV;
  msg.subtype = 1;
  msg.pid = getpid();
  strcpy(msg.nick_name, argv[1]);
  msgsnd(msgid, & msg, MSG_LEN, 0); //MSG_LEN是消息正文大小 

  //客户端双进程实现读和写操作
  if ((pid = fork()) < 0) {
    perror("fork error.");
    exit(-1);
  } else if (pid == 0) { //子进程专门负责读消息
    while (1) {
      //msgid为消息队列的队列ID
      //&msg为消息类型为TYPE_ME的消息缓冲区首地址
      //0指定了阻塞式等待
      msgrcv(msgid, & msg, MSG_LEN, TYPE_ME, 0);

      //判断接收到的消息是否为quit
      if (strncmp(msg.mtext, "quit", 4) == 0) {
        printf("[server will close in 3 seconds...]\n");
        kill(getppid(), SIGUSR1); //若收到quit通知父进程并自己退出
        exit(0);
      }
      if (strncmp(msg.mtext, "exit", 4) == 0) {
        msg.subtype = 3;
      }

      //写成switch方便以后扩展
      switch (msg.subtype) {
      case 1:
        printf("[%s on line]\n", msg.nick_name);
        break;
      case 2:
        printf("[%s]\n", msg.nick_name);
        printf("%s", msg.mtext);
        break;
      case 3:
        printf("[%s off line]", msg.nick_name);
        break;
      default:
        break;
      }
    }
  } else { //父进程专门负责写消息
    msg.mtype = TYPE_SRV; //设定服务器的发送类型
    msg.subtype = 2; //设为广播模式
    while (1) {
      printf("[%s]\n", msg.nick_name);
      fgets(msg.mtext, N, stdin);
      msgsnd(msgid, & msg, MSG_LEN, 0);
      //当此进程输入exit时，表示该进程退出聊天
      //由服务器通知其他进程，该进程已下线    
      if (strncmp(msg.mtext, "exit", 4) == 0) {
        msg.subtype = 3;
        msgsnd(msgid, & msg, MSG_LEN, 0);
        sleep(1);
        kill(pid, SIGKILL);
        exit(0);
      }
    }
  }
  return 0;
}
