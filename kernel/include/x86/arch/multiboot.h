#ifndef __X86_ARCH_MULTIBOOT_H__
#define __X86_ARCH_MULTIBOOT_H__

#include <stdint.h>

#define MULTIBOOT_AVAILABLE 1

struct multiboot_info {
	uint32_t flags;

	uint32_t mem_lower;
	uint32_t mem_upper;

	uint32_t boot_device;

	uint32_t cmdline;

	uint32_t mods_count;
	uint32_t mods_addr;

	/* elf section header or a.out symbol table, anyway we don't care */
	uint32_t dummy[4];

	/* this fields, really, the only we need, so far */
	uint32_t mmap_length;
	uint32_t mmap_addr;

	uint32_t drives_length;
	uint32_t drives_addr;

	uint32_t config_table;

	uint32_t boot_loader_name;

	uint32_t apm_table;

	uint32_t vbe_control_info;
	uint32_t vbe_mode_info;
	uint32_t vbe_mode;
	uint32_t vbe_interface_seg;
	uint32_t vbe_interface_off;
	uint32_t vbe_interface_len;
} __attribute__((packed));

struct multiboot_mmap_entry
{
	uint32_t size;
	uint64_t addr;
	uint64_t len;
	uint32_t type;
} __attribute__((packed));

#endif /*__X86_ARCH_MULTIBOOT_H__*/
