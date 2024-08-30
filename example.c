#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/netdevice.h>

static int device_event(unsigned long event, struct net_device *dev)
{
	switch (event) {
	case NETDEV_CHANGEMTU:
		netdev_info(dev, "mtu changed on device to %d",
			    dev->mtu);
		break;
	default:
		break;
	}

	return NOTIFY_DONE;
}

static int example_netdev_event(struct notifier_block *this,
			     unsigned long event, void *ptr)
{
	struct net_device *event_dev = netdev_notifier_info_to_dev(ptr);

	netdev_dbg(event_dev, "%s received %s\n",
		   __func__, netdev_cmd_to_name(event));

	return device_event(event, event_dev);
}

static struct notifier_block example_netdev_notifier = {
	.notifier_call = example_netdev_event,
};

static int __init example_init(void)
{
	register_netdevice_notifier(&example_netdev_notifier);
	printk(KERN_INFO "Hello world 1.\n");

	return 0;
}

static void __exit example_exit(void)
{
	unregister_netdevice_notifier(&example_netdev_notifier);
	printk(KERN_INFO "Goodbye world 1.\n");
}


module_init(example_init);
module_exit(example_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example <example@example.edu.>");
MODULE_DESCRIPTION("\"Hello, world!\" minimal module");
MODULE_VERSION("printk");

