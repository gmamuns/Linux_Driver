obj-m += Hello.o
KDIR = /usr/src/linux-header-3.2.0-24-generic-pae
all:
	$(Make) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod *.symvers *.order