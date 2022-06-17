#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/err.h>

static struct task_struct *kthread_test = NULL;
static int myVal = 1;

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
static int MyPrintk(void *data)
{
	while(!kthread_should_stop())
	{
        char* info = itos(myVal);
        write_file(info, "/root/lock/output");
        kfree(info);
        myVal++;
        ssleep(1);
	}    
	return 0;
}
static int __init init_mytask(void)
{
    kthread_test = kthread_run(&MyPrintk, NULL, "kthreadtest");
    return 0;
}
static void __exit exit_mytask(void)
{
    if (kthread_test)
    {
        kthread_stop(kthread_test);
        kthread_test = NULL;
    }
}

module_init(init_mytask);
module_exit(exit_mytask);
MODULE_LICENSE("GPL");