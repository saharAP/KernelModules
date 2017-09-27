/* logPacket.c */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SAHAR");
MODULE_DESCRIPTION("a simple module that logs everytime your computer recives a packet");


static struct nf_hook_ops nfho;


unsigned int my_hook(unsigned int hooknum,
    struct sk_buff *skb,
    const struct net_device *in,
    const struct net_device *out,
    int (*okfn)(struct sk_buff *))  {
    struct sock *sk = skb->sk;
    printk("Hello packet!");
    return NF_ACCEPT;
}


static int init_filter_if(void)
{
  nfho.hook = my_hook;
  nfho.hooknum = 0 ; //NF_IP_PRE_ROUTING;
  nfho.pf = PF_INET;
  nfho.priority = NF_IP_PRI_FIRST;

  nf_register_hook(&nfho);

  return 0;
}

static int __init logPacket_init(void)
{
	printk(KERN_INFO "hello logPacket module!\n");
	init_filter_if();
	return 0;
}

static void __exit logPacket_exit(void)
{
	nf_unregister_hook(&nfho);
	printk(KERN_INFO "module unloaded!\n");
}

module_init(logPacket_init)
module_exit(logPacket_exit)
