#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static struct task_struct *kthread_test = NULL;


static int MyPrintk(void *data)
{
    while (!kthread_should_stop())
    {
        int cpu = get_cpu();
        put_cpu();
        printk("hello kernel thread %s, cpu = %d\n", kthread_test->comm, cpu);
        msleep(2000);
    }
	return 0;
}

static int __init init_kthread(void)
{
    printk("Kernel thread start");
    kthread_test = kthread_create(MyPrintk, NULL, "kthreadtest");
    kthread_bind(kthread_test, 1);
    wake_up_process(kthread_test);
    return 0;
}

static void __exit exit_kthread(void)
{
    printk("Kill new kthread.\n");
    if(kthread_test)
    {
        kthread_stop(kthread_test);
    }
}

module_init(init_kthread);
module_exit(exit_kthread);
MODULE_LICENSE("GPL");