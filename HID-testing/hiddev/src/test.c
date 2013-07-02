/* 
 * Test code for inspecting HID reports
 *
 * Most code was borrowed from libacinfo: https://github.com/darkscout/libacinfo
 *
 */ 

/*
 * Per http://forum.aquacomputer.de/berwachung-und-steuerung/102304-hid-reports-f-r-aquaero-et-al/
 *
 * The following reports are available on the AQ5:
 * 	1,3,4,5,6,7,8,9,10,11,12
 * 
 * Details:
USAGE_PAGE (Vendor Defined Page 1) 06 00 FF
USAGE (Vendor Usage 1) 09 01
COLLECTION (Application) A1 01 
  REPORT_ID (1) 85 01 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (626) 96 72 02 
  USAGE (Vendor Usage 1) 09 01
  INPUT (Data, Var, Abs) 81 02 

  REPORT_ID (3) 85 03 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (7) 95 07 
  USAGE (Vendor Usage 1) 09 01
  INPUT (Data, Var, Abs) 81 02 

  REPORT_ID (4) 85 04 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (2113) 96 41 08 
  USAGE (Vendor Usage 1) 09 01
  OUTPUT (Data, Var, Abs) 91 02 

  REPORT_ID (5) 85 05 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (4) 96 04 00 
  USAGE (Vendor Usage 1) 09 01
  OUTPUT (Data, Var, Abs) 91 02 

  REPORT_ID (6) 85 06 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (8) 95 08 
  USAGE (Vendor Usage 1) 09 01
  OUTPUT (Data, Var, Abs) 91 02 

  REPORT_ID (7) 85 07 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (8) 95 08 
  USAGE (Vendor Usage 1) 09 01
  OUTPUT (Data, Var, Abs) 91 02 

  REPORT_ID (8) 85 08 
  REPORT_COUNT (2112) 96 40 08 
  USAGE (Undefined) 09 00
  FEATURE (Data, Var, Abs, Buf) B2 01 02 

  REPORT_ID (9) 85 09 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (521) 96 09 02 
  USAGE (Vendor Usage 1) 09 01
  OUTPUT (Data, Var, Abs) 91 02 

  REPORT_ID (10) 85 0A 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (27) 95 1B 
  USAGE (Vendor Usage 1) 09 01
  OUTPUT (Data, Var, Abs) 91 02 

  REPORT_ID (11) 85 0B 
  REPORT_COUNT (2247) 96 C7 08 
  USAGE (Undefined) 09 00
  FEATURE (Data, Var, Abs, Buf) B2 01 02 

  REPORT_ID (12) 85 0C 
  LOGICAL_MINIMUM (0) 15 00 
  LOGICAL_MAXIMUM (255) 26 FF 00 
  REPORT_SIZE (8) 75 08 
  REPORT_COUNT (521) 96 09 02 
  USAGE (Vendor Usage 1) 09 01
  INPUT (Data, Var, Abs) 81 02 
END_COLLECTION C0


From Firmware 1027 these have been found to be:

6 0 ff	(usage page, vendor defined page 1)
9 1 	(usage, vendor usage 1)
a1 1	(collection, application)

85 1	(report ID 1) 
15 0	(logical min 0)
26 ff 0	(logical max 255)
75 8	(report size 8)
96 92 2	(report count 658)
9 1	(vendor usage 1) 
81 2 	(input)

85 3 	(report ID 3)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 7 0 	(report count 7)
9 1 	(vendor usage 1)
81 2 	(input)

85 4 	(Report ID 4)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 41 8 (report count 2113)
9 1 	(vendor usage 1)
91 2	(output) 

85 5 	(Report ID 5)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 4 0	(report count 4)
9 1 	(vendor usage 1)
91 2	(output) 

85 6 	(Report ID 6)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 4 0 	(report count 4)
9 1 	(vendor usage 1)
91 2 	(output)

85 7 	(Report ID 7)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 10 0 (report count 16)
9 1 	(vendor usage 1)
91 2 	(output)

85 8	(Report ID 8) 
96 40 8 (report size 2112)
9 0 	(usage undefined)
b2 2 1	(feature) 

85 a 	(Report ID 10)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 1b 0 (report count 27)
9 1 	(vendor usage 1)
91 2	(output) 

85 b 	(Report ID 11)
96 7b 9 (report size 2427)
9 0 	(usage undefined)
b2 2 1	(feature) 

85 9 	(Report ID 9)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 b 2 	(report count 523)
9 1 	(vendor usage 1)
91 2	(output)

85 c 	(Report ID 12)
15 0 	(logical min 0)
26 ff 0 (logical max 255)
75 8 	(report size 8)
96 b 2 	(report count 523)
9 1 	(vendor usage 1)
81 2 	(input)

c0 (end collection) 


*/

#include "test.h"


#define REPORT	11
/* #define REPORT_INPUT_LEN	2247 */
#define REPORT_INPUT_LEN	32768
#define REPORT_OUTPUT_LEN	16


int main (int argc, char *argv[]) 
{
	int fd, bytes;
	unsigned char *buffer = (unsigned char*)malloc(REPORT_INPUT_LEN);
	unsigned char *o_buffer = (unsigned char*)malloc(REPORT_OUTPUT_LEN);
	struct hiddev_devinfo dinfo;
	struct hiddev_string_descriptor hStr;
	u_int32_t version;
	
	/* Open our device */
	/* fd = open("/dev/usb/hiddev0", O_RDONLY); */
	fd = open("/dev/usb/hiddev0", O_RDWR);

	if (fd < 0) {
		printf("Sorry, cannot open device for reading!\n");
		return -1;
	}

	ioctl(fd, HIDIOCGVERSION, &version);
	printf("hiddev driver version is %d.%d.%d\n", version >> 16, (version >> 8) & 0xff, version & 0xff);

	ioctl(fd, HIDIOCGDEVINFO, &dinfo);
	printf("HID: vendor 0x%x product 0x%x(0x%x) version 0x%x\n", dinfo.vendor, dinfo.product & 0xffff, dinfo.product, dinfo.version);

	if ((dinfo.vendor == 0xc70) && ((dinfo.product & 0xffff) == 0xf001)) {
		hStr.index = 2; /* Vendor = 1, Product = 2 */
		hStr.value[0] = 0;
		ioctl(fd, HIDIOCGSTRING, &hStr);
		printf("Found '%s'\n", hStr.value);

		/* Initing all feature and input reports */
		printf("Initing all input and feature reports.\n");
		if (ioctl(fd, HIDIOCINITREPORT, 0) < 0)
			printf("Failed to init reports!\n");

		/* Method 1 */
		printf("\n*** FEATURE:\n"); showReports(fd, HID_REPORT_TYPE_FEATURE);
		printf("\n*** INPUT:\n"); showReports(fd, HID_REPORT_TYPE_INPUT);
		/* no point in reading outputs since they are just 0 for all values */
		/* printf("\n*** OUTPUT:\n"); showReports(fd, HID_REPORT_TYPE_OUTPUT); */
		
		/* Lets set some values in the buffer */
		o_buffer[0] = 0x08;
		o_buffer[1] = 0x98;
		o_buffer[2] = 0x7f;
		o_buffer[3] = 0xff;
		o_buffer[4] = 0x7f;
		o_buffer[5] = 0xff;
		o_buffer[6] = 0x7f;
		o_buffer[7] = 0xff;
		o_buffer[8] = 0x7f;
		o_buffer[9] = 0xff;
		o_buffer[10] = 0x7f;
		o_buffer[11] = 0xff;
		o_buffer[12] = 0x7f;
		o_buffer[13] = 0xff;
		o_buffer[14] = 0x7f;
		o_buffer[15] = 0xff;

		printf("\n*** Setting output report:\n"); hiddev_set_report(fd, HID_REPORT_TYPE_OUTPUT, 0x7, o_buffer);

		/* Method 2 (Doesn't work on my systems) */
		bytes = hiddev_get_feature_report(fd, 0xB, buffer, REPORT_INPUT_LEN);
        
		if (bytes <= 0)
		{
			free(buffer);
			printf("Oops, this report provided no data!\n");
			close(fd);
			return -1;
		} else {
			debug_buffer_hex(buffer, REPORT_INPUT_LEN);
			close(fd);
			return 0;
		}
	} else {
		return -1;
	} 
}

static void hiddev_set_report(int fd, unsigned report_type, int report_id, unsigned char *buffer)
{
	struct hiddev_report_info rinfo;
	struct hiddev_field_info finfo;
	struct hiddev_usage_ref uref;
	int i;

	/* find the requested usage code */
	uref.report_type = report_type;
	uref.report_id   = report_id;
	uref.field_index = 0;
	uref.usage_index = 0;
	/* fetch the usage code for given indexes */
	if (ioctl(fd, HIDIOCGUCODE, &uref) < 0)
	{
		printf("Oops! HIDIOCGUCODE failed!\n");
		return;

	}

	/* uref.usage_code  = (0x82 << 16) | code; */
	if (ioctl(fd, HIDIOCGUSAGE, &uref) < 0)
	{
		printf("Oops! HIDIOCGUSAGE failed!\n");
		return;
	}

	printf(" >> usage_index=%u usage_code=0x%X value=%d\n",
		uref.usage_index,
		uref.usage_code,
		uref.value);

	/* retrieve field info */
	finfo.report_type = uref.report_type;
	finfo.report_id   = uref.report_id;
	finfo.field_index = uref.field_index;
	if (ioctl(fd, HIDIOCGFIELDINFO, &finfo) < 0)
	{
		printf("Oops! HIDIOCGFIELDINFO failed!\n");
		return;
	}

	printf("HIDIOCGFIELDINFO: field_index=%u maxusage=%u flags=0x%X\n"
 		"\tphysical=0x%X logical=0x%X application=0x%X\n"
		"\tlogical_minimum=%d,maximum=%d physical_minimum=%d,maximum=%d\n",
		finfo.field_index, finfo.maxusage, finfo.flags,
		finfo.physical, finfo.logical, finfo.application,
		finfo.logical_minimum,  finfo.logical_maximum,
		finfo.physical_minimum, finfo.physical_maximum);

	/* set values */
	for(i=0; i<finfo.maxusage; i++) {
		uref.report_type = finfo.report_type;
		uref.report_id   = finfo.report_id;
		uref.field_index = 0;
		uref.usage_index = i;
		/* check limits */
		/* TODO: are the logical limits the ones we want to check against? */
		if ((buffer[i] < finfo.logical_minimum) || (buffer[i] > finfo.logical_maximum))
		{
			printf("%d: value %d outside of allowed range (%d-%d)\n",
				uref.usage_code, buffer[i],
				finfo.logical_minimum,  finfo.logical_maximum);
			return;
		}
		uref.value = (__s32)buffer[i];
		/* set the value from report */
		if (ioctl(fd, HIDIOCSUSAGE, &uref) < 0) {
			printf("Oops! HIDIOCSUSAGE failed!\n");
			return;
		}
	}

	printf("Sending the following in the report:\n");
	debug_buffer_hex(buffer, REPORT_OUTPUT_LEN);

	printf("HIDIOCSUSAGE\n");

	rinfo.report_type = uref.report_type;
	rinfo.report_id   = uref.report_id;
	rinfo.num_fields = 1;
	if (ioctl(fd, HIDIOCSREPORT, &rinfo) < 0)
	{
		printf("Oops! HIDIOCSREPORT failed\n");
		return;
	}
	printf("HIDIOCSREPORT\n");
}

int hiddev_get_feature_report(int fd, int report_id, unsigned char *buffer, int length)
{
	struct hiddev_report_info rinfo;
	struct hiddev_field_info finfo;
  	struct hiddev_usage_ref_multi ref_multi_i;
	int ret, report_length, i;

	finfo.report_type = HID_REPORT_TYPE_FEATURE;
	finfo.report_id = report_id;
	finfo.field_index = 0;

	/* request info about the feature report (get byte length) */
        ret = ioctl(fd, HIDIOCGFIELDINFO, &finfo);

	report_length = finfo.maxusage;

	if (report_length > length)
	{
		fprintf(stderr, "Buffer too small. Report length %d, buffer length %d\n", report_length, length);
		/* buffer too small */
		return 0;
	} else {
		if (report_length <= 0) {
			fprintf(stderr, "Bailing out, report length = %d\n",report_length);
			return 0;
		} else {
			fprintf(stderr, "Continuing, report length %d - buffer length %d\n", report_length, length);
		}
	}


	rinfo.report_type = HID_REPORT_TYPE_FEATURE;
	rinfo.report_id = report_id;
	rinfo.num_fields = 1;

	ref_multi_i.uref.report_type = HID_REPORT_TYPE_FEATURE;
	ref_multi_i.uref.report_id = report_id;
	ref_multi_i.uref.field_index = 0;
	ref_multi_i.uref.usage_index = 0; /* byte index??? */
	ref_multi_i.num_values = report_length;

	/* request feature report */
        ret = ioctl(fd, HIDIOCGREPORT, &rinfo);
        
	if (ret != 0)
	{
		fprintf(stderr, "HIDIOCGREPORT (%s)\n", strerror(errno));
		return 0;
	}                

        /* multibyte transfer to local buffer */
	ret = ioctl(fd, HIDIOCGUSAGES, &ref_multi_i);

	if (ret != 0)
	{
		fprintf(stderr, "HIDIOCGUSAGES (%s)\n", strerror(errno));
		return 0;
	}                

	/* copy bytes to output buffer (missing the first byte - report id)
  	 * can't use memcpy, because values are signed int32 
  	 */
	for(i=0; i<report_length-1; i++)
		buffer[i] = ref_multi_i.values[i];


	return report_length;
}


void debug_buffer_hex(unsigned char *buffer, int len) 
{
	int i;

	printf( "hex-dump of buffer:\n" );
	printf( "---------------------------\n" );

	for(i=0; i < len; i++) 
	{
		unsigned char c = (unsigned char)buffer[i];
		printf( "%02X ", (int)c );

		if((i+1) % 16 == 0 ) printf( "\n" );
	}
	printf( "\n" "---------------------------" "\n" );
}

void debug_buffer(char *buffer, int len) 
{
	int i;
	char tmp[2];
	tmp[0] = ' ';
	tmp[1] = '\0';

	printf( "buffer:\n>>>\n" );
	for(i = 0; i < len; ++i) 
	{
		char c = buffer[i];

		if ((c >= ' ' && c <= 'z') || (c == 0x0d)  || (c == 0x0a))
		{
			tmp[0] = c;
		}
		else
		{
			tmp[0] = '*';
		}

		printf("%s", (char*)tmp);
	}
	printf("\n<<<\n");
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

			if(ioctl(fd, HIDIOCGREPORT, &rinfo) != 0) {
				fprintf(stderr, "Failed to HIDIOCGREPORT for report %d\n", finfo.report_id);
			}

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

