kernelsrc=$(shell uname -r)

obj-m += hello.o

all:
	make -C /lib/modules/$(kernelsrc)/build  M=$(PWD) modules



clean:
	make -C /lib/modules/$(kernelsrc)/build  M=$(PWD) clean 
