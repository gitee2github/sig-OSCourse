#include <linux/module.h>
#include <asm/io.h>
#include <linux/ioport.h>

MODULE_LICENSE("GPL");

struct resource * myregion;

static int __init mem_module_init(void)
{
	printk("Start request mem region!\n");

	myregion = request_mem_region(0x3b410000, 10,"ve");

	if (myregion != NULL){
		printk("it's ok for %lld .",myregion->start);
		
	}else{
		printk("Failed to request region!\n");
	}

	return 0;
}

static void __exit mem_module_exit(void)
{
	 release_mem_region(0x3b410000, 10); 
	printk("Exit request_region!\n");
}

module_init(mem_module_init);
module_exit(mem_module_exit);
