#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/version.h>
#include <asm/uaccess.h> 
#include <linux/random.h>
//#include <stdio.h>
//#include "/usr/include/stdio.h"
//#include "/usr/include/"
#define FILE_NAME "driverSensVent"

static struct proc_dir_entry *my_proc_file;

static ssize_t my_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{
    pr_info("%s my_read handler\n", FILE_NAME);
    char greeting[] = "Hello World !\n";
    int greeting_length = strlen(greeting);
 if (*offset > 0)
  return 0;

//unsigned int random_ticket;
// () not needed with sizeof object
//get_random_bytes(&random_ticket, sizeof random_ticket); 

// Best to use unsigned constants with unsigned objects.
//random_ticket = 1u + (random_ticket % 7u);
int i, lessthan100;
get_random_bytes(&i, sizeof(i));
lessthan100 = i % 100;
char str = lessthan100+'0';
int number=7;
char charValue = number+'0';
pr_info("number generated", greeting_length);
//printk(charValue, "number generated");

copy_to_user(buffer, charValue, greeting_length);
*offset = greeting_length;

 return greeting_length;
}

static ssize_t my_write(struct file *file, const char __user *buffer, size_t length, loff_t *offset)
{
    pr_info("%s my_write handler\n", FILE_NAME);
    return -1;
}

static const struct proc_ops proc_file_fops = {
    .proc_read = my_read,
    .proc_write = my_write
};

static int __init proc_init(void)
{
    my_proc_file = proc_create(
        FILE_NAME,
        0666,
        NULL,
        &proc_file_fops
    );

    return 0;
}

static void __exit proc_exit(void)
{
    proc_remove(my_proc_file);
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
