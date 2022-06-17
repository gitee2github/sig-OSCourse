obj-m :=workqueue_test1.o

CURRENT_PATH:=$(shell pwd)
LINUX_PATH:=/root/raspberrypi-kernel

all:
	$(MAKE) -C $(LINUX_PATH) M=$(CURRENT_PATH) modules

clean:
	rm *.mod.c *.o *.order *.symvers *.ko
