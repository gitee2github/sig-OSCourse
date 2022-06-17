#include <linux/module.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");

struct timeval tv;

/* Load module. */
static int __init task1_init(void)
{
	int sec, usec;
	printk("task1 init\n");
	do_gettimeofday(&tv);
	sec = (int)tv.tv_sec;
	usec = (int)tv.tv_usec;
	printk("The sec and usec from 1970 is: [%d sec, %d usec]\n", sec, usec);
	return 0;
}

/* Unload module. */
static void __exit task1_exit(void)
{
	printk("task1 exit\n");
}

module_init(task1_init);
module_exit(task1_exit);
