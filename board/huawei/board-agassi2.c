/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Board driver for Huawei Mediapad T5
 *
 * Copyright (c) 2025, Tildeguy <tildeguy@proton.me>
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <lib/debug.h>

#define UART_BASE 0xfdf02000

void uart_putc(char ch)
{
	// no uart for now
}

void uart_puts(const char *s)
{
	while (*s != '\0') {
		uart_putc(*s);
		s++;
	}
}

static struct video_info agassi2_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1080,
	.height = 1920,
	.stride = 4,
	.address = (void *)0xe8600000
};

int agassi2_drv(void)
{
	REGISTER_DRIVER("simplefb", simplefb_probe, &agassi2_fb);
	return 0;
}

struct board_data board_ops = {
	.name = "huawei-agassi2",
	.ops = {
		.drivers_init = agassi2_drv,
	},
	.quirks = 0
};
