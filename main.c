#include<linux/module.h>
#include<linux/fs.h>
#include<linux/init.h>
#include<linux/cdev.h>
#define DEV_MEM_SIZE 512
char device_buffer[DEV_MEM_SIZE];

struct class* pcd_class;
struct device* pcd_device;
dev_t device_number;

struct cdev pcd_cdev;

loff_t pcd_llseek(struct file* filp,loff_t f_pos,int whence){
	return 0;
};
ssize_t pcd_read(struct file* filp,char* __user buff,size_t count,loff_t* f_pos){
	return 0;
};

ssize_t pcd_write(struct file* filp,const char* __user buff,size_t count,loff_t* f_pos){
	return 0;
};

int pcd_open(struct inode* inode,struct file* filp){
	return 0;
};

int pcd_release(struct inode* indoe ,struct file* filp){
	return 0;
};
struct file_operations pcd_fops = {
	.owner = THIS_MODULE,
	.open = pcd_open,
	.release = pcd_release,
	.read = pcd_read,
	.write = pcd_write,
};

static int __init pcd_driver_init(void){
	// dynamically allocate a device number
	alloc_chrdev_region(&device_number,0,1,"pcd");
	printk(KERN_INFO "Device created with %d:%d",MAJOR(device_number),MINOR(device_number));
	// initialize the cdev structure with pcd_fops
	cdev_init(&pcd_cdev,&pcd_fops);
	pcd_cdev.owner = THIS_MODULE;
	cdev_add(&pcd_cdev,device_number,1);
	pcd_class = class_create("pcd_class");
	pcd_device = device_create(pcd_class,NULL,device_number,NULL,"pcd");
	return 0;
}

static void __exit pcd_driver_exit(void){
	
}

module_init(pcd_driver_init);
module_exit(pcd_driver_exit);
MODULE_AUTHOR("teiwiet");
MODULE_DESCRIPTION("test pseudo char driver");
MODULE_LICENSE("GPL");
