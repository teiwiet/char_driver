#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kernel.h>
static int __init module_init(){
	return 1;
}

static void __exit module_exit(){

}

module_init(module_init);
module_exit(module_exit);
MODULE_AUTHOR("teiwiet");
MODULE_DESCRIPTION("Simple kernel driver by teiwiet");
MODULE_LICENSE("GPL");
