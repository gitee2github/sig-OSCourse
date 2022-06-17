#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
#include <linux/uaccess.h>

#include <linux/fs.h>

struct proc_dir_entry *sigkill_dir;
char pid[10] = {'\0'};

static int sigkill_proc_show(struct seq_file *m, void *v) {
	seq_printf(m, "%s", pid);
	return 0;
}


static int sigkill_proc_open(struct inode *inode, struct  file *file) {
	
	return single_open(file, sigkill_proc_show, NULL);
}

static ssize_t myproc_write(struct file *file, const char __user *buffer, size_t count, loff_t *data)
{
	unsigned long count2 = count;

    if (count2 >= sizeof(pid))
    	count2 = sizeof(pid) - 1;

    if (copy_from_user(pid, buffer, count2))
       	return -EFAULT;

   	return (ssize_t)count;
}


static const struct file_operations sigkill_proc_fops = {
	.owner = THIS_MODULE,
	.open = sigkill_proc_open,
	.read = seq_read,
	.write = myproc_write,
	.llseek = seq_lseek,
	.release = single_release,
};

static int __init hello_proc_init(void) {
	sigkill_dir = proc_mkdir("sigkill" ,NULL);
	proc_create("sigkill", 0, sigkill_dir, &sigkill_proc_fops);
	return 0;
}

static void __exit hello_proc_exit(void) {
	remove_proc_entry("sigkill", sigkill_dir);
	remove_proc_entry("sigkill", NULL);
}

MODULE_LICENSE("GPL");
module_init(hello_proc_init);
module_exit(hello_proc_exit);
