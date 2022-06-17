#include <linux/module.h>
#include <linux/time.h>
#include <linux/rtc.h>

MODULE_LICENSE("GPL");

struct timeval tv;
struct rtc_time tm;

static int __init task2_init(void)
{
	int year, mon, day, hour, min, sec;
	printk("task2 init\n");
	do_gettimeofday(&tv);
	rtc_time_to_tm(tv.tv_sec, &tm);
	year = tm.tm_year + 1900;
	mon = tm.tm_mon + 1;
	day = tm.tm_mday;
	hour = tm.tm_hour + 8;
	min = tm.tm_min;
	sec = tm.tm_sec;
	printk("Current time: %d-%02d-%02d %02d:%02d:%02d\n", year, mon, day, hour, min, sec);
	return 0;
}

static void __exit task2_exit(void)
{
	printk("task2 exit\n");
}

module_init(task2_init);
module_exit(task2_exit);
