#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/err.h>
#include <linux/spinlock.h>
#include <linux/sched.h>
#include <linux/seqlock.h>

static struct task_struct *Thread1 = NULL;
static struct task_struct *Thread2 = NULL;
static seqlock_t lock;
static int count = 0;
static int myVar = 0;


static void setMyVar(int input){
	write_seqlock(&lock);
	printk("try to lock setmyvar\n");
	if(count){
		printk("busy setmyvar\n");
	}
        //临界区
	printk("lock setmyvar\n");
	count++;
   myVar = input;
	printk("setmyvar is %d \n",myVar);
        
   write_sequnlock(&lock);
	printk("unlock setmyvar\n");
	count--;
}
static int getMyVar(void){
	unsigned long seq;
	int ret;
	do{
		seq= read_seqbegin(&lock);
		ret=myVar;
	}while(read_seqretry(&lock,seq));
	return ret;
}
static int length(int value)
{
    int len = 1;
    value /= 10;
    while (value)
    {
        len++;
        value /= 10;
    }
    return len;
}
static char* itos(int value)
{
    int len = length(value);
    char* info = (char*) kmalloc(len + 2, GFP_ATOMIC);
    int index = len - 1;
    info[index--] = value % 10 + '0';
    value /= 10;
    while(value)
    {
        info[index--] = value % 10 + '0';
        value /= 10;
    }
    info[len] = '\n';
    info[len + 1] = '\0';
    return info;
}
struct file * open_file(char* filename)
{
    struct file * fp = filp_open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (IS_ERR(fp))
    {
        printk("Create file error\n");
        return NULL;
    }
    return fp;
}
static int write_file(char* info, char* filename)
{
    struct file * fp = open_file(filename);
    kernel_write(fp, info, strlen(info), &fp->f_pos);
    filp_close(fp, NULL);
    return 0;
}
static int ThreadOne(void *data)
{	
    int i = 100;
	while(!kthread_should_stop())
	{
	    printk("enter threadone\n");
        write_file("enter threadone\n", "/root/seqlock/output");
        char* info = itos(getMyVar());
        write_file("Thread one get: ", "/root/seqlock/output");
        write_file(info, "/root/seqlock/output");
        kfree(info);
        setMyVar(i);
        info = itos(getMyVar());
        write_file("Thread one set: ", "/root/seqlock/output");
        write_file(info, "/root/seqlock/output");
        kfree(info);
        write_file("leave threadone\n", "/root/seqlock/output");
        ssleep(1);
        i++;	
	}    
	return 0;
}
static int ThreadTwo(void *data)
{	
    int j = 0;
	while(!kthread_should_stop())
	{
        printk("enter threadtwo\n");
        char* info = itos(getMyVar());
        write_file("enter threadtwo\n", "/root/spinlock/output");
        write_file("Thread two get: ", "/root/spinlock/output");
        write_file(info, "/root/spinlock/output");
        kfree(info);
        setMyVar(j);
        info = itos(getMyVar());
        write_file("Thread two set: ", "/root/spinlock/output");
        write_file(info, "/root/spinlock/output");
        kfree(info);
        write_file("leave threadtwo\n", "/root/spinlock/output");
        ssleep(1);
        j++;	
	}    
	return 0;
}
int init_lock(void ){
    seqlock_init(&lock);	
    return 0;
}

static int __init init_mytask(void)
{
    init_lock();
    Thread1 = kthread_run(ThreadOne, NULL, "thread1");
	Thread2 = kthread_run(ThreadTwo, NULL, "thread2");
    return 0;
}
static void __exit exit_mytask(void)
{
	if(Thread1){
		printk("stop thread1");
		kthread_stop(Thread1);
	}
	if(Thread2){
		printk("stop thread2");
		kthread_stop(Thread2);
	}
}   

module_init(init_mytask);
module_exit(exit_mytask);
MODULE_LICENSE("GPL");