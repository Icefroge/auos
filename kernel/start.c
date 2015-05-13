#include <kernel/page_alloc.h>
#include <kernel/kernel.h>
#include <kernel/debug.h>

extern void setup_arch(void *bootstrap);

void zone_stat(struct zone *zone)
{
	debug("start pfn = %d, end pfn = %d\n",
		zone->start_pfn, zone->end_pfn);

	for (unsigned i = 0; i != MAX_ORDER; ++i) {
		struct list_head *head = &zone->free_area[i];
		struct list_head *curr = head->next;
		unsigned total = 0;

		while (curr != head) {
			curr = curr->next;
			++total;
		}

		debug("There are %d blocks of order %d\n", total, i);
	}
}

void stat(void)
{
	for (unsigned i = 0; i != ZONE_TYPES; ++i)
		zone_stat(&nodes[0].zones[i]);
}

void start_kernel(void *bootstrap)
{
	setup_arch(bootstrap);

	stat();

	while (1);
}
