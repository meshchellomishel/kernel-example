
***
### Module entry/exit points

Module entry function - this is function from `module_init(`**FUNCTION**`)`

There is template:

```
static int __init init_func(void)
{
	return 0;
}

module_init(init_func);
```

***__init***:
```
/* These macros are used to mark some functions or 
 * initialized data (doesn't apply to uninitialized data)
 * as `initialization' functions. The kernel can take this
 * as hint that the function is used only during the initialization
 * phase and free up used memory resources after
 *
 * Usage:
 * For functions:
 * 
 * You should add __init immediately before the function name, like:
 *
 * static void __init initme(int x, int y)
 * {
 *    extern int z; z = x * y;
 * }
 *
 * If the function has a prototype somewhere, you can also add
 * __init between closing brace of the prototype and semicolon:
 *
 * extern int initialize_foobar_device(int, int, int) __init;
 *
 * For initialized data:
 * You should insert __initdata or __initconst between the variable name
 * and equal sign followed by value, e.g.:
 *
 * static int init_variable __initdata = 0;
 * static const char linux_logo[] __initconst = { 0x32, 0x36, ... };
 *
 * Don't forget to initialize data not at file scope, i.e. within a function,
 * as gcc otherwise puts the data into the bss section and not into the init
 * section.
 */
```


Maybe for optimization we should use ***__initdata*** in init funtions? 
