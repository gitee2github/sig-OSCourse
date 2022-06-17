#include <linux/module.h>
#include <linux/rtc.h>
#include <linux/delay.h>
#include <linux/kthread.h>

MODULE_LICENSE("GPL");

struct timeval tv;
struct rtc_time tm;
static struct task_struct *myThread=NULL;
int start;
int end;

static int getCurrentTime(void)
{
	int year, mon, day, hour, min, sec;
	do_gettimeofday(&tv);
	rtc_time_to_tm(tv.tv_sec, &tm);
	year = tm.tm_year + 1900;
	mon = tm.tm_mon + 1;
	day = tm.tm_mday;
	hour = tm.tm_hour + 8;
	min = tm.tm_min;
	sec = tm.tm_sec;
	printk("UTC time: %d-%02d-%02d %02d:%02d:%02d]\n", year, mon, day, hour, min, sec);
	return (int)tv.tv_sec;
}

static int print(void *data)
{
	int count = 0;
	while(!kthread_should_stop()){
		printk("Thread function: iteration %d\n", ++count);
		msleep(2000);
	}
	return 0;
}

static int __init task4_init(void)
{
	printk("thread create time->[ ");
	myThread = kthread_run(print, "hello world", "mythread");
	start = getCurrentTime();
	return 0;
}

static void __exit task4_exit(void)
{
	if(myThread){
		kthread_stop(myThread);
		printk("thread die time->[ ");
		end = getCurrentTime();
		printk("thread life time: %d s\n", end-start);
	}
}

module_init(task4_init);
module_exit(task4_exit);
