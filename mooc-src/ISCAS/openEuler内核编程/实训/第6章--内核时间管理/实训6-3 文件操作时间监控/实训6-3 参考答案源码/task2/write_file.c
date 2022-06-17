#include <linux/module.h>
#include <linux/fs.h>
#include <linux/rtc.h>

#define BUF_SIZE 76
#define write_times 100000

MODULE_LICENSE("GPL");

struct timeval tv;
int start_time;
int start_time_u;
int end_time;
int end_time_u;
long write_time;

static int __init write_file_init(void)
{
	struct file *file_write;
	char buf[BUF_SIZE];
	int i;	
	loff_t pos = 0;

	printk("Start file writing process !\n");
	for(i = 0; i < BUF_SIZE; i++){
		buf[i] = i + '0';
	}
	buf[BUF_SIZE - 1] = '\n';

	file_write = filp_open("/home/output_file100000.txt", O_RDWR | O_CREAT, 0644);
	if (IS_ERR(file_write)){
		printk("Failed to open file.\n");
		return -1;
	}
	do_gettimeofday(&tv);
	start_time = (int)tv.tv_sec;
	start_time_u = (int)tv.tv_usec;

	for(i = 0; i < write_times; i++)
		kernel_write(file_write, buf, BUF_SIZE, &pos);

	do_gettimeofday(&tv);
	end_time = (int)tv.tv_sec;
	end_time_u = (int)tv.tv_usec;
	filp_close(file_write, NULL);
	write_time = (end_time - start_time) * 1000000 + (end_time_u - start_time_u);
	printk("It takes %ld us to write to a file.\n", write_time);
	printk("And writing times is: %d.\n", write_times);
	return 0;
}

static void __exit write_file_exit(void)
{
	printk("Exit writing process !\n");
}

module_init(write_file_init);
module_exit(write_file_exit);
