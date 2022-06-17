#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static struct task_struct *myThread = NULL;

static int print(void *data)
{
	int count = 0;
	while(!kthread_should_stop()){
		printk("Thread function: iteration %d\n", ++count);
		msleep(2000);
	}
	return 0;
}

static int __init task3_init(void)
{
	printk("task3 init\n");
	myThread = kthread_run(print, NULL, "mythread");
	return 0;
}

static void __exit task3_exit(void)
{
	printk("task3 exit\n");
	if(myThread)
		kthread_stop(myThread);
}

module_init(task3_init);
module_exit(task3_exit);
