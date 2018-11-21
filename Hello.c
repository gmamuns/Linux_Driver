
#include <linux/init.h>
#include <linux/module.h> 

//Step 01
#include <linux/moduleparam.h>

//Step 02 : Create Variable
// int param_var = 0;
int param_var[3] ={0,0,0};

//Step 03 : Register (macro)
// module_param(name_var,type,permissions)
module_param(param_var,int,NULL, S_IRUSR | S_IWUSR);

void display(){
    //printk(KERN_ALERT "TEST : param = %d",param_var); // For Single int value
    printk(KERN_ALERT "TEST : param = %d",param_var[0]);
    printk(KERN_ALERT "TEST : param = %d",param_var[1]);
    printk(KERN_ALERT "TEST : param = %d",param_var[2]);
    
}
/*
S_IRUSR ->
S_IWUSR ->
S_IXUSR ->
S_IWGRP ->
S_IRGRP ->
S_IRUSR | S_IWUSR ->
*/

static int hello_init(void){
    printk(KERN_ALERT "TEST : Hello World. \n")
    display();
    return 0;
}

static void hello_exit(void){
    printk(KERN_ALERT "TEST : Good Bye.")
}

module_init(hello_init);
module_exit(hello_exit);

/*
 > save file and make "Makefile"
 > Terminal :> insmod Hello.ko param_var=24,535,190
            :> dmesg     (will show all message)
            :> rmmod Hello.ko
*/