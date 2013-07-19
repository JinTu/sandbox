/*
 * Hidraw Userspace Example
 *
 * Copyright (c) 2010 Alan Ott <alan@signal11.us>
 * Copyright (c) 2010 Signal 11 Software
 *
 * The code may be used by anyone for any purpose,
 * and can serve as a starting point for developing
 * applications using hidraw.
 */

/* Linux */
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hidraw.h>
#include <linux/hiddev.h>
/*
 * Ugly hack to work around failing compilation on systems that don't
 * yet populate new version of hidraw.h to userspace.
 *
 * If you need this, please have your distro update the kernel headers.
 */
#ifndef HIDIOCSFEATURE
#define HIDIOCSFEATURE(len)    _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x06, len)
#define HIDIOCGFEATURE(len)    _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x07, len)
#endif

/* Unix */
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

const char *bus_str(int bus);
static void showReports(int fd, unsigned report_type);

int main(int argc, char **argv)
{
	int fd;
	int i, res, desc_size = 0;
	char buf[256];
	struct hidraw_report_descriptor rpt_desc;
	struct hidraw_devinfo info;

	/* Open the Device with non-blocking reads. In real life,
	   don't use a hard coded path; use libudev instead. */
	/* fd = open("/dev/hidraw2", O_RDWR|O_NONBLOCK); */
	fd = open("/dev/hidraw2", O_RDONLY);

	if (fd < 0) {
		perror("Unable to open device");
		return 1;
	}

	memset(&rpt_desc, 0x0, sizeof(rpt_desc));
	memset(&info, 0x0, sizeof(info));
	memset(buf, 0x0, sizeof(buf));

	/* Get Report Descriptor Size */
	res = ioctl(fd, HIDIOCGRDESCSIZE, &desc_size);
	if (res < 0)
		perror("HIDIOCGRDESCSIZE");
	else
		printf("Report Descriptor Size: %d\n", desc_size);

	/* Get Report Descriptor */
	rpt_desc.size = desc_size;
	res = ioctl(fd, HIDIOCGRDESC, &rpt_desc);
	if (res < 0) {
		perror("HIDIOCGRDESC");
	} else {
		printf("Report Descriptor:\n");
		for (i = 0; i < rpt_desc.size; i++)
			printf("%hhx ", rpt_desc.value[i]);
		puts("\n");
	}

	/* Get Raw Name */
	res = ioctl(fd, HIDIOCGRAWNAME(256), buf);
	if (res < 0)
		perror("HIDIOCGRAWNAME");
	else
		printf("Raw Name: %s\n", buf);

	/* Get Physical Location */
	res = ioctl(fd, HIDIOCGRAWPHYS(256), buf);
	if (res < 0)
		perror("HIDIOCGRAWPHYS");
	else
		printf("Raw Phys: %s\n", buf);

	/* Get Raw Info */
	res = ioctl(fd, HIDIOCGRAWINFO, &info);
	if (res < 0) {
		perror("HIDIOCGRAWINFO");
	} else {
		printf("Raw Info:\n");
		printf("\tbustype: %d (%s)\n",
			info.bustype, bus_str(info.bustype));
		printf("\tvendor: 0x%04hx\n", info.vendor);
		printf("\tproduct: 0x%04hx\n", info.product);
	}

	/* Get the feature reports (hiddev method) */
	printf("\n*** FEATURE:\n"); showReports(fd, HID_REPORT_TYPE_FEATURE);
	printf("\n*** INPUT:\n"); showReports(fd, HID_REPORT_TYPE_INPUT);

	/* Get Feature */
	buf[0] = 0xB; /* Report Number */
	res = ioctl(fd, HIDIOCGFEATURE(256), buf);
	if (res < 0) {
		perror("HIDIOCGFEATURE");
	} else {
		printf("ioctl HIDIOCGFEATURE returned: %d\n", res);
		printf("Report data (not containing the report number):\n\t");
		for (i = 0; i < res; i++)
			printf("%hhx ", buf[i]);
		puts("\n");
	}

	/* Get a report from the device */
	res = read(fd, buf, 16);
	if (res < 0) {
		perror("read");
	} else {
		printf("read() read %d bytes:\n\t", res);
		for (i = 0; i < res; i++)
			printf("%hhx ", buf[i]);
		puts("\n");
	}

	close(fd);
	return 0;
}

const char *
bus_str(int bus)
{
	switch (bus) {
	case BUS_USB:
		return "USB";
		break;
	case BUS_HIL:
		return "HIL";
		break;
	case BUS_BLUETOOTH:
		return "Bluetooth";
		break;
	case BUS_VIRTUAL:
		return "Virtual";
		break;
	default:
		return "Other";
		break;
	}
}

static void showReports(int fd, unsigned report_type)
{
        struct hiddev_report_info rinfo;
        struct hiddev_field_info finfo;
        struct hiddev_usage_ref uref;
        int i, j, ret;

        rinfo.report_type = report_type;
        rinfo.report_id = HID_REPORT_ID_FIRST;
        ret = ioctl(fd, HIDIOCGREPORTINFO, &rinfo);
        while (ret >= 0)
        {
                printf("HIDIOCGREPORTINFO: report_id=0x%X (%u fields)\n",
                        rinfo.report_id, rinfo.num_fields);
                for (i = 0; i < rinfo.num_fields; i++)
                {
                        finfo.report_type = rinfo.report_type;
                        finfo.report_id   = rinfo.report_id;
                        finfo.field_index = i;
                        ioctl(fd, HIDIOCGFIELDINFO, &finfo);

                        printf("HIDIOCGFIELDINFO: field_index=%u maxusage=%u flags=0x%X\n"
                                "\tphysical=0x%X logical=0x%X application=0x%X\n"
                                "\tlogical_minimum=%d,maximum=%d physical_minimum=%d,maximum=%d,type=%u\n",
                                finfo.field_index, finfo.maxusage, finfo.flags,
                                finfo.physical, finfo.logical, finfo.application,
                                finfo.logical_minimum,  finfo.logical_maximum,
                                finfo.physical_minimum, finfo.physical_maximum, finfo.report_type);

                        for (j = 0; j < finfo.maxusage; j++)
                        {
                                uref.report_type = finfo.report_type;
                                uref.report_id   = finfo.report_id;
                                uref.field_index = i;
                                uref.usage_index = j;
                                /* fetch the usage code for given indexes */
                                ioctl(fd, HIDIOCGUCODE, &uref);
                                /* fetch the value from report */
                                ioctl(fd, HIDIOCGUSAGE, &uref);

                               	/*
                              	printf(" >> usage_index=%u usage_code=0x%X value=%d\n",
                              	uref.usage_index,
                              	uref.usage_code,
                               	uref.value);
				*/
                                /* printf("%d\n",uref.value); */

                                if (((j) % 16 == 0 )) printf("%08X  ", j);
                                printf("%02X ", uref.value);
                                if((j+1) % 16 == 0 ) printf( "\n" );

                        }
                }
                printf("\n");

                rinfo.report_id |= HID_REPORT_ID_NEXT;
                ret = ioctl(fd, HIDIOCGREPORTINFO, &rinfo);
        }
}

