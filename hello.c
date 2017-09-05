/* hello.c */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void){

pr_alert("hello init");
return 0;

}
