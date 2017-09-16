/* hello.c */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


static char* whom="World";

module_param(whom,charp,0);

static int howmany=1;

module_param(howmany,int,0);

static int __init hello_init(void){

int i;

for(i=0;i<howmany;i++){

pr_alert("(%d)hello %s\n",i,whom);

}
return 0;

}

static void __exit hello_exit(void){

pr_alert("exit %s",whom);
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting module");
MODULE_AUTHOR("William Shakespeare");
