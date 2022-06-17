#include <linux/module.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL");

struct timer_list timer;

void print(struct timer_list *timer)
{
	printk("hello,world!\n");
}

static int __init timer_init(void)
{
	printk("timer init\n");
	timer.expires = jiffies + 10 * HZ;
	timer.function = print;
	add_timer(&timer);
	return 0;
}

static void __exit timer_exit(void)
{
	printk("timer exit\n");
}

module_init(timer_init);
module_exit(timer_exit);
