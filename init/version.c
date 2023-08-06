// SPDX-License-Identifier: GPL-2.0-only
/*
 *  linux/init/version.c
 *
 *  Copyright (C) 1992  Theodore Ts'o
 *
 *  May be freely distributed as part of Linux.
 */

#include <generated/compile.h>
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export.h>
#include <linux/init.h>
#include <linux/printk.h>
#include <linux/uts.h>
#include <linux/utsname.h>
#include <linux/proc_ns.h>


/**
 * early_hostname - set hostname early parameter
 * @arg: hostname string
 * @return: 0 on success, -EINVAL if the hostname is too long
*/
static int __init early_hostname(char *arg)
{
	size_t bufsize = sizeof(init_uts_ns.name.nodename);
	/* bufsize is the size of the buffer that will hold the hostname */
	
	size_t maxlen  = bufsize - 1;
	/* Max len is the maximum size of the buffer 
	 * that can be held in the kernel. This is ussually
	 * 64 bytes. */

	size_t arglen;

	arglen = strlcpy(init_uts_ns.name.nodename, arg, bufsize);
	/* Using strlcpy we can copy the string and return the length
	 * of the string. If the length of the string is greater than
	 * the buffer size, then the string is truncated */

	if (arglen > maxlen) {
		pr_warn("hostname parameter exceeds %zd characters and will be truncated",
			maxlen);
		return -EINVAL; /* Return a error since the string is too long */
	}
	return 1; /* Return 1 on success */
}
early_param("hostname", early_hostname);

const char linux_proc_banner[] =
	"%s version %s"
	" (" LINUX_COMPILE_BY "@" LINUX_COMPILE_HOST ")"
	" (" LINUX_COMPILER ") %s\n";

BUILD_SALT;
BUILD_LTO_INFO;

/*
 * init_uts_ns and linux_banner contain the build version and timestamp,
 * which are really fixed at the very last step of build process.
 * They are compiled with __weak first, and without __weak later.
 */

struct uts_namespace init_uts_ns __weak;
const char linux_banner[] __weak;

#include "version-timestamp.c"

EXPORT_SYMBOL_GPL(init_uts_ns);
