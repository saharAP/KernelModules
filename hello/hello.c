/* hello.c */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

static char* whom="World";

module_param(whom,charp,0);

static int howmany=1;

module_param(howmany,int,0);

static int  hello_init(void){

int i;

for(i=0;i<howmany;i++){

pr_alert("(%d)hello %s\n",i,whom);

}
return 0;

}

static void  hello_exit(void){

printk(KERN_ALERT "hello exit\n");
printk(KERN_INFO "The process is \"%s\" (pid %i)\n",current->comm, current->pid);
//pr_alert("exit %s",whom);
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting module");
MODULE_AUTHOR("William Shakespeare");
