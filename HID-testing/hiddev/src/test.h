#ifndef TEST_H
#define TEST_H 1

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <fcntl.h> 
#include <errno.h>

#include <linux/hiddev.h>

/*
 * The Aqua Computer Aquastream XT shows itself as a HID (Human Interface Device) usb device 
 * and communicates via Feature Reports.
 *  
 * With the following GET and SET functions these can be used.
 * 
 */

static void hiddev_set_report(int fd, unsigned report_type, int report_id, unsigned char *buffer);
int hiddev_get_feature_report(int fd, int report_id, unsigned char *buffer, int length);

/* prints out every printable byte from a buffer.
 * unprintable bytes are replaced with '*' 
 */
void debug_buffer(char *buffer, int len);

/* prtints out a buffer as hex */
void debug_buffer_hex(unsigned char *buffer, int len);

/* Dump the report info */
static void showReports(int fd, unsigned report_type);


#endif
