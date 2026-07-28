/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Board driver for Huawei Mediapad T5
 *
 * Copyright (c) 2026, Tildeguy <tildeguy@mainlining.org>
 */

#include <board.h>
#include <util.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>
#include <soc/hi6250.h>

int agassi2_early_init(void)
{
	hi6250_enable_frp();
	return 0;
}

int agassi2_late_init(void)
{
#ifdef CONFIG_HUAWEI_AGASSI2_DISABLE_WDT
	hi6250_disable_wdt();
#endif
	return 0;
}

static struct video_info agassi2_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1200,
	.height = 1920,
	.stride = 4,
	.address = (void *)0x5d000000,
	.scale = 2
};

static const struct device agassi2_devices[] = {
	{ "simplefb", &agassi2_fb, "fb" },
};

struct board_data board_ops = {
	.name = "huawei-agassi2",
	.ops = {
		.early_init = agassi2_early_init,
		.late_init = agassi2_late_init,
	},
	.devices = agassi2_devices,
	.num_devices = ARRAY_SIZE(agassi2_devices),
	.quirks = 0
};
