/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Tildeguy <tildeguy@mainlining.org>
 */

#include <soc/hi6250.h>

void hi6250_disable_wdt(void)
{
	volatile unsigned int *wdt_control =
		(volatile unsigned int *)(SP805_WDT_BASE + SP805_WDTCONTROL);
	volatile unsigned int *wdt_lock =
		(volatile unsigned int *)(SP805_WDT_BASE + SP805_WDTLOCK);

	*wdt_lock = SP805_WDT_UNLOCK_KEY;
	*wdt_control = 0;
	*wdt_lock = SP805_WDT_LOCK_KEY;
	(void)*wdt_lock;
}

void hi6250_enable_frp(void)
{
	unsigned long cpacr;
	__asm__ volatile ("mrs %0, cpacr_el1" : "=r" (cpacr));
	cpacr |= (3UL << 20);
	__asm__ volatile ("msr cpacr_el1, %0" :: "r" (cpacr));
}

void soc_init(void) {
  // hi6250_enable_frp();
  // // soc_init is never used
}
