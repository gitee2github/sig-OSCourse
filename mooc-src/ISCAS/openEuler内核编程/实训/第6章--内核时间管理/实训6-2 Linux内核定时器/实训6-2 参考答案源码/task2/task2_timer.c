#include <linux/module.h>
#include <linux/timer.h>
#include <linux/delay.h>
#include <linux/atomic.h>

MODULE_LICENSE("GPL");

struct timer_list timer;
static atomic_t flag = ATOMIC_INIT(0);

void print(struct timer_list *timer)
{
	atomic_set(&flag, 1);
	printk("hello,world!\n");
}

static int __init timer_init(void)
{
	int count = 0;
	printk("timer init\n");
	timer.expires = jiffies + 10 * HZ;
	timer.function = print;
	add_timer(&timer);
	mod_timer(&timer, jiffies + 15 * HZ);
	while(atomic_read(&flag) == 0){
		msleep(1000);
		printk("%dth second\n", ++count);
	}
	return 0;
}

static void __exit timer_exit(void)
{
	printk("timer exit\n");
}

module_init(timer_init);
module_exit(timer_exit);
