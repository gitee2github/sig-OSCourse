#include <linux/module.h>
#include <linux/sched/signal.h>
#include <linux/mm_types.h>

MODULE_LICENSE("GPL");

static int __init maxPro_init(void)
{
	struct task_struct *p;
	printk("maxPro init\n");
	for_each_process(p){
		if(p->mm != NULL){
			printk("1)name:%s  2)pid:%d  3)state:%ld  4)mem:%lu\n", p->comm, p->pid, p->state, p->mm->total_vm);
		}
	}
	return 0;
}

static void __exit maxPro_exit(void)
{
        printk("maxPro exit\n");
}

module_init(maxPro_init);
module_exit(maxPro_exit);
