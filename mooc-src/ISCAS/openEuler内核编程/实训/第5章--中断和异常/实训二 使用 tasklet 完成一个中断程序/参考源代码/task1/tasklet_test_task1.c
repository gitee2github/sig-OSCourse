#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static char *who = "world";
static int times = 1;
module_param(times, int, S_IRUSR);
module_param(who, charp, S_IRUSR);
static int hello_init(void)
{
	int i;
	for (i = 0; i < times; i++)
		printk(KERN_ALERT "(%d) hello, %s!\n", i, who);
	return 0;
}
static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, %s!\n", who);
}
module_init(hello_init);
module_exit(hello_exit);