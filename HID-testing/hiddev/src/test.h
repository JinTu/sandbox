#ifndef TEST_H
#define TEST_H 1

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <time.h>

#include <sys/ioctl.h>
#include <fcntl.h> 
#include <errno.h>

#include <linux/hiddev.h>

typedef enum {
	NAME_BUTTON,
	NAME_SENSOR,
	NAME_POWERADJUST,
	NAME_SOFTWARE_SENSOR,
	NAME_VIRTUAL_SENSOR,
	NAME_MPS,
	NAME_AQUASTREAM,
	NAME_SENSOR_EXT1,
	NAME_FAN_AMPLIFIER,
	NAME_CPU,
	NAME_SENSOR_EXT2,
	NAME_FAN,
	NAME_FLOW,
	NAME_PROFILE,
	NAME_AQUASTREAM_XT,
	NAME_MULTISWITCH,
	NAME_TARGET_VALUE_CONT,
	NAME_CURVE_CONT,
	NAME_TWO_POINT_CONT,
	NAME_PRESET_VALUE_CONT,
	NAME_POWER_OUTPUT,
	NAME_ALERT_LEVEL,
	NAME_AQ5,
	NAME_FILL_LEVEL,
	NAME_PRESSURE,
	NAME_HUMIDITY,
	NAME_WATER_QUALITY,
	NAME_MPS_D5
} name_enum_t;

typedef struct {
	uint8_t	address;
	uint8_t	count;
} name_position_t;

name_position_t name_position[] = {
	[NAME_BUTTON] 		= { 0,	16 },
	[NAME_SENSOR] 		= { 16,	8 },
	[NAME_POWERADJUST] 	= { 24,	8 },
	[NAME_SOFTWARE_SENSOR] 	= { 32,	8 },
	[NAME_VIRTUAL_SENSOR] 	= { 40,	4 },
	[NAME_MPS] 		= { 44,	8 },
	[NAME_AQUASTREAM] 	= { 52,	2 },
	[NAME_SENSOR_EXT1] 	= { 54,	6 },
	[NAME_FAN_AMPLIFIER] 	= { 60,	12 },
	[NAME_CPU] 		= { 72,	1 },
	[NAME_SENSOR_EXT2] 	= { 73, 7 },
	[NAME_FAN] 		= { 80,	12 },
	[NAME_FLOW] 		= { 92,	14 },
	[NAME_PROFILE] 		= { 106,	4 },
	[NAME_AQUASTREAM_XT] 	= { 110,	2 },
	[NAME_MULTISWITCH] 	= { 112,	2 },
	[NAME_TARGET_VALUE_CONT] = { 114,	8 },
	[NAME_CURVE_CONT] 	= { 122,	4 },
	[NAME_TWO_POINT_CONT] 	= { 126,	16 },
	[NAME_PRESET_VALUE_CONT] = { 142,	8 },
	[NAME_POWER_OUTPUT]	= { 150,	2 },
	[NAME_ALERT_LEVEL] 	= { 152,	8 },
	[NAME_AQ5] 		= { 160,	1 },
	[NAME_FILL_LEVEL] 	= { 161,	4 },
	[NAME_PRESSURE] 	= { 165,	4 },
	[NAME_HUMIDITY] 	= { 169,	4 },
	[NAME_WATER_QUALITY] 	= { 173,	4 },
	[NAME_MPS_D5] 		= { 177,	4 }
};

/*
 * The Aqua Computer Aquastream XT shows itself as a HID (Human Interface Device) usb device 
 * and communicates via Feature Reports.
 *  
 * With the following GET and SET functions these can be used.
 * 
 */

static void hiddev_set_report(int fd, unsigned report_type, int report_id, unsigned char *buffer);
int hiddev_get_feature_report(int fd, unsigned report_type, int report_id, unsigned char *buffer, int length);

/* inserts the uint16 into the offset provided in the char array */
static void set_uint16(unsigned char *buffer, short offset, uint16_t val);

/* prints out every printable byte from a buffer.
 * unprintable bytes are replaced with '*' 
 */
void debug_buffer(char *buffer, int len);

/* prtints out a buffer as hex */
void debug_buffer_hex(unsigned char *buffer, int len);

/* Dump the report info */
static void showReports(int fd, unsigned report_type);
static void showReport(int fd, unsigned report_type, int report_id, unsigned char *buffer);

/* Do an interrupt read */
static void interruptRead(int fd, int report_id, unsigned char *buffer, int len, int count);

#endif
