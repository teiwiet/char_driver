#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#define MEM_SIZE 512

char device_buffer[MEM_SIZE];
dev_t device_number;
int ret;
struct cdev pcd_cdev; 

loff_t pcd_llseek(struct file* filp,loff_t f_pos,int whence){
	return 0;
}

ssize_t pcd_read(struct file* filp,char* __user buff,size_t count,loff_t* f_pos){
	return 0;
}

ssize_t pcd_write(struct file* filp,const char* __user buff,size_t count,loff_t* f_pos){
	return 0;
}

int pcd_open(struct inode* inode,struct file* filp){
	return 0;
}

int pcd_release(struct inode* inode,struct file* filp){
	return 0;
}

struct file_operations pcd_fops = {
	.owner = THIS_MODULE,
	.llseek = pcd_llseek,
	.read = pcd_read,
	.write = pcd_write,
	.open = pcd_open,
	.release = pcd_release
};




static int __init pcd_init(void){
	ret = alloc_chrdev_region(&device_number,0,1,"pcd_device");
	cdev_init(&pcd_cdev,&pcd_fops);
	pcd_cdev.owner = THIS_MODULE;
	cdev_add(&pcd_cdev,device_number,1);
	pr_info(KERN_INFO "what the fuck i didn't print any thing :-))");
	return 0;
}


static void __exit pcd_exit(void){

};




module_init(pcd_init);
module_exit(pcd_exit);

MODULE_AUTHOR("teiwiet");
MODULE_DESCRIPTION("Simple LKM by teiwiet");
MODULE_LICENSE("GPL");

