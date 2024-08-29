#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init example_init(void)
{
	printk(KERN_INFO "Hello world 1.\n");

	return 0;
}

static void __exit example_exit(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}


module_init(example_init);
module_exit(example_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example <example@example.edu.>");
MODULE_DESCRIPTION("\"Hello, world!\" minimal module");
MODULE_VERSION("printk");

