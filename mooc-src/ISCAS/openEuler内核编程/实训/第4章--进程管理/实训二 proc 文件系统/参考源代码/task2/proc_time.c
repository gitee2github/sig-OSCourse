#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/timer.h>  
#include <linux/rtc.h>  

#define IS_LEAP_YEAR(year) !(year%400)||(year%100&&!(year%4))
struct proc_dir_entry *time_dir;
static int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

static int hello_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "Hello proc\n");
	return 0;
}

static int hello_proc_open(struct inode *inode, struct  file *file) {
	return single_open(file, hello_proc_show, NULL);
}

static const struct file_operations hello_proc_fops = {
	.owner = THIS_MODULE,
	.open = hello_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static int time_proc_show(struct seq_file *m, void *v) {
	struct timeval tv;  
	struct rtc_time tm;  
	int year,month,day,hour;
	int carry = 0;
	do_gettimeofday(&tv);
	rtc_time_to_tm(tv.tv_sec,&tm);
	
	hour = (tm.tm_hour + 8)%24;
	carry = (tm.tm_hour + 8)/24;
	
	if(IS_LEAP_YEAR(tm.tm_year) && (tm.tm_mon  == 1)) {     
		day = (tm.tm_mday + carry)%(mon[tm.tm_mon] + 1);
		carry = (tm.tm_mday + carry)/(mon[tm.tm_mon] + 2);
	}
	else {
		day = (tm.tm_mday + carry)%mon[tm.tm_mon];
		carry = (tm.tm_mday + carry)/(mon[tm.tm_mon] + 1);
	}
	
	month = (tm.tm_mon + carry)%12 + 1;
	carry = (tm.tm_mon + carry)/12;
	
	year = tm.tm_year + 1900 + carry;
	seq_printf(m, "UTC time :%d-%d-%d %d:%d:%d \n",year, month, day, hour, tm.tm_min,tm.tm_sec);
	return 0;
}

static int time_proc_open(struct inode *inode, struct  file *file) {
	return single_open(file, time_proc_show, NULL);
}

static const struct file_operations time_proc_fops = {
	.owner = THIS_MODULE,
	.open = time_proc_open,
	.read = seq_read,
	.llseek = seq_lseek,
	.release = single_release,
};

static int __init time_proc_init(void) {
    proc_create("hello", 0, NULL, &hello_proc_fops);
	time_dir = proc_mkdir("show_time" ,NULL);
	proc_create("proc_time", 0, time_dir, &time_proc_fops);
	return 0;
}

static void __exit time_proc_exit(void) {
    remove_proc_entry("hello", NULL);
	remove_proc_entry("proc_time", time_dir);
	remove_proc_entry("show_time", NULL);
}

MODULE_LICENSE("GPL");
module_init(time_proc_init);
module_exit(time_proc_exit);
