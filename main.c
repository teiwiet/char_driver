#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>
#define DEV_MEM_SIZE 512
char device_buffer[DEV_MEM_SIZE];
dev_t device_number;


static int __init pcd_driver_init(void){
	alloc_chrdev_region(&device_number,0,1,"pcd");
	return 0;
}


static void __exit pcd_driver_exit(void){
	
}


module_init(pcd_driver_init);
module_exit(pcd_driver_exit);
MODULE_AUTHOR("teiwiet");
MODULE_DESCRIPTION("test pseudo char driver");
MODULE_LICENSE("GPL");
