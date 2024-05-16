#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>
#include<linux/cdev.h>
#define DEV_MEM_SIZE 512
char device_buffer[DEV_MEM_SIZE];

dev_t device_number;

struct cdev pcd_cdev;

struct file_operations pcd_fops;

static int __init pcd_driver_init(void){
	// dynamically allocate a device number
	alloc_chrdev_region(&device_number,0,1,"pcd");
	// initialize the cdev structure with pcd_fops
	cdev_init(&pcd_cdev,&pcd_fops);
	pcd_cdev.owner = THIS_MODULE;
	cdev_add(&pcd_cdev,device_number,1);
	return 0;
}

static void __exit pcd_driver_exit(void){
	
}

module_init(pcd_driver_init);
module_exit(pcd_driver_exit);
MODULE_AUTHOR("teiwiet");
MODULE_DESCRIPTION("test pseudo char driver");
MODULE_LICENSE("GPL");
