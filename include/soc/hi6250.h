
/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2026, Tildeguy <tildeguy@mainlining.org>
 */

#ifndef HI6250_H_	/* Include guard */
#define HI6250_H_

#define SP805_WDT_BASE        0xE8A06000U

#define SP805_WDTCONTROL      0x008U
#define SP805_WDTLOCK         0xC00U

#define SP805_WDT_UNLOCK_KEY  0x1ACCE551U
#define SP805_WDT_LOCK_KEY    0x00000001U

void hi6250_enable_frp(void);
void hi6250_disable_wdt(void);

#endif // HI6250_H_
