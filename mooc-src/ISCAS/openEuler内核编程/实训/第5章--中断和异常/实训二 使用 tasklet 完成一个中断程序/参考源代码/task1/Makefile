obj-m +=tasklet_test_task1.o 
CURRENT_PATH := $(shell pwd)	
LINUX_KERNEL_PATH := /root/raspberrypi-kernel  # 这里我们只需要指定一个与内核版本一致的源码路径就行了
all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules  
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko