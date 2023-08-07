/* SPDX-License-Identifier: GPL-2.0 */
/**
 * printk_clear_debug.h - print a kernel debugging message that is
 * easy to spot and clear in the log
 * 
 * By: Lewis Evans
 * Date: 2023/08/07
*/

#ifndef _LINUX_PRINTK_CLEAR_DEBUG_H
#define _LINUX_PRINTK_CLEAR_DEBUG_H


#include <linux/printk.h>

#ifdef CONFIG_PRINTK_CLEAR_DEBUG
/**
 * printk_clear_debug() - print a kernel debugging message that is
 * clear and easy to spot in the log. This is useful for debugging
 * when there are lots of other messages in the log. It will also
 * show up in the log even when the debug level is turned off.
 * 
 * To show or hide these messages that may have been left in the code
 * set in the kernel config: CONFIG_PRINTK_CLEAR_DEBUG
 * 
*/
#define printk_clear_debug(fmt, ...) \
    printk("====================[ DEBUG ]====================\n" \
        fmt "\n" \
        "==================[ END DEBUG ]==================\n", \
        ##__VA_ARGS__)

#else
/**
 * If we dont want to show these messages, then just define the macro
 * to do nothing. Then the user wont see the messages in the log.
*/
#define printk_clear_debug(fmt, ...) do {} while (0)
#endif /* CONFIG_PRINTK_CLEAR_DEBUG */
#endif /* _LINUX_PRINTK_DEBUG_H */