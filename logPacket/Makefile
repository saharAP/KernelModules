obj-m := logPacket.o

KERNELDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	make -C $(KERNELDIR) M=$(PWD) 

clean:
	make -C $(KERNELDIR) M=$(PWD) clean
