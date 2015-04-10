#ifndef __KERNEL_CONSOLE_H__
#define __KERNEL_CONSOLE_H__

#include <kernel/list.h>

struct console {
	struct list_head link;
	void (*write)(const char *data, unsigned long size);
};

extern struct list_head consoles;

void register_console(struct console *console);
void unregister_console(struct console *console);

#endif /*__KERNEL_CONSOLE_H__*/
