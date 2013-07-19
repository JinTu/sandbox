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
#define REPORT_NAME_LEN		523
#define REPORT_SETTINGS_LEN	2427
#define CLEAN_NAME_LEN		4096

inline uint16_t aq5_get_int16(unsigned char *buffer, short offset)
{
	return (uint16_t)((buffer[offset] << 8) | buffer[offset + 1]);
}

inline int check_and_strip_name_report_watermarks(unsigned char *dirtybuffer, unsigned char *cleanbuffer)
{
	typedef struct {
		uint16_t offset;
		uint16_t value;
	} name_report_watermark;

	name_report_watermark* watermarks = malloc(6 * 8 * sizeof(name_report_watermark)); 
	/* 1 
 	 * start 0x0000: 01 00 09 c0 00 00 00 02 00
 	 * end 0x0209: DD 83
 	 */
	watermarks[0].offset = 0x0000;
	watermarks[0].value = 0x0100;
	watermarks[1].offset = 0x0002;
	watermarks[1].value = 0x09c0;
	watermarks[2].offset = 0x0004;
	watermarks[2].value = 0x0000;
	watermarks[3].offset = 0x0006;
	watermarks[3].value = 0x0002;
	watermarks[4].offset = 0x0007;
	watermarks[4].value = 0x0200;
	watermarks[5].offset = 0x0209;
	watermarks[5].value = 0xdd83;

	/* 2
 	 * start 0x020b: 01 00 09 C2 00 00 00 02 00
 	 * end 0x0414: DD 84
 	 */ 
	watermarks[6].offset = 0x020b;
	watermarks[6].value = 0x0100;
	watermarks[7].offset = 0x020d;
	watermarks[7].value = 0x09c2;
	watermarks[8].offset = 0x020f;
	watermarks[8].value = 0x0000;
	watermarks[9].offset = 0x0211;
	watermarks[9].value = 0x0002;
	watermarks[10].offset = 0x0212;
	watermarks[10].value = 0x0200;
	watermarks[11].offset = 0x0414;
	watermarks[11].value = 0xdd84;

	/* 3
 	 * start 0x0416: 01 00 09 C4 00 00 00 02 00
 	 * end 0x061f: DD 85
  	 */
	watermarks[12].offset = 0x0416;
	watermarks[12].value = 0x0100;
	watermarks[13].offset = 0x0418;
	watermarks[13].value = 0x09c4;
	watermarks[14].offset = 0x041a;
	watermarks[14].value = 0x0000;
	watermarks[15].offset = 0x041c;
	watermarks[15].value = 0x0002;
	watermarks[16].offset = 0x041d;
	watermarks[16].value = 0x0200;
	watermarks[17].offset = 0x061f;
	watermarks[17].value = 0xdd85;

	/* 4
 	 * start 0x0621: 01 00 09 C6 00 00 00 02 00
 	 * end 0x082a: DD 86
 	 */
	watermarks[18].offset = 0x0621;
	watermarks[18].value = 0x0100;
	watermarks[19].offset = 0x0623;
	watermarks[19].value = 0x09c6;
	watermarks[20].offset = 0x0625;
	watermarks[20].value = 0x0000;
	watermarks[21].offset = 0x0627;
	watermarks[21].value = 0x0002;
	watermarks[22].offset = 0x0628;
	watermarks[22].value = 0x0200;
	watermarks[23].offset = 0x082a;
	watermarks[23].value = 0xdd86;

	/* 5
 	 * start 0x082c: 01 00 09 C8 00 00 00 02 00
 	 * end 0x0a35: DD 87
 	 */
	watermarks[24].offset = 0x082c;
	watermarks[24].value = 0x0100;
	watermarks[25].offset = 0x082e;
	watermarks[25].value = 0x09c8;
	watermarks[26].offset = 0x0830;
	watermarks[26].value = 0x0000;
	watermarks[27].offset = 0x0832;
	watermarks[27].value = 0x0002;
	watermarks[28].offset = 0x0833;
	watermarks[28].value = 0x0200;
	watermarks[29].offset = 0x0a35;
	watermarks[29].value = 0xdd87;

	/* 6
 	 * start 0x0a37: 01 00 09 CA 00 00 00 02 00
 	 * end 0x0c40: DD 88
 	 */
	watermarks[30].offset = 0x0a37;
	watermarks[30].value = 0x0100;
	watermarks[31].offset = 0x0a39;
	watermarks[31].value = 0x09ca;
	watermarks[32].offset = 0x0a3b;
	watermarks[32].value = 0x0000;
	watermarks[33].offset = 0x0a3d;
	watermarks[33].value = 0x0002;
	watermarks[34].offset = 0x0a3e;
	watermarks[34].value = 0x0200;
	watermarks[35].offset = 0x0c40;
	watermarks[35].value = 0xdd88;

	/* 7
 	 * start 0x0c42: 01 00 09 CC 00 00 00 02 00
 	 * end 0x0e4b: DD 89
 	 */
	watermarks[36].offset = 0x0c42;
	watermarks[36].value = 0x0100;
	watermarks[37].offset = 0x0c44;
	watermarks[37].value = 0x09cc;
	watermarks[38].offset = 0x0c46;
	watermarks[38].value = 0x0000;
	watermarks[39].offset = 0x0c48;
	watermarks[39].value = 0x0002;
	watermarks[40].offset = 0x0c49;
	watermarks[40].value = 0x0200;
	watermarks[41].offset = 0x0e4b;
	watermarks[41].value = 0xdd89;

	/* 8
 	 * start 0x0e4d: 01 00 09 CE 00 00 00 02 00
 	 * end 0x1056 : DD 8A
 	 */
	watermarks[42].offset = 0x0e4d;
	watermarks[42].value = 0x0100;
	watermarks[43].offset = 0x0e4f;
	watermarks[43].value = 0x09ce;
	watermarks[44].offset = 0x0e51;
	watermarks[44].value = 0x0000;
	watermarks[45].offset = 0x0e53;
	watermarks[45].value = 0x0002;
	watermarks[46].offset = 0x0e54;
	watermarks[46].value = 0x0200;
	watermarks[47].offset = 0x1056;
	watermarks[47].value = 0xdd8a;

	for (int i=0; i<48; i++) {
		if (aq5_get_int16(dirtybuffer, watermarks[i].offset) != watermarks[i].value) {
			printf("Oops watermark at offset %02X is %02X (index %d), but should be %02X!\n", watermarks[i].offset, aq5_get_int16(dirtybuffer, watermarks[i].offset), i, watermarks[i].value);
			return -1;
		} else {
			/* printf("i=%d\n",i); */
		}
	}

	/* Initialize cleanbuffer */
	memset(cleanbuffer, 0, 8 * 512 * sizeof(char));

	for (int i=0; i<8; i++) {
		memcpy(cleanbuffer + (512 * i), dirtybuffer + 9 + (i * 523), 512 * sizeof(char));
	}

	return 0;
}

int main (int argc, char *argv[]) 
{
	int fd, bytes;
	unsigned char *buffer = (unsigned char*)malloc(REPORT_INPUT_LEN);
	unsigned char *o_buffer = (unsigned char*)malloc(REPORT_OUTPUT_LEN);
	unsigned char *name_buffer = (unsigned char*)malloc(REPORT_NAME_LEN * 8);
	unsigned char *rname_buffer = (unsigned char*)malloc(REPORT_NAME_LEN);
	unsigned char *settings_buffer = (unsigned char*)malloc(REPORT_SETTINGS_LEN);
	unsigned char *clean_name_buffer = (unsigned char*)malloc(CLEAN_NAME_LEN);
	struct hiddev_devinfo dinfo;
	struct hiddev_string_descriptor hStr;
	u_int32_t version;
	int flag = HIDDEV_FLAG_UREF | HIDDEV_FLAG_REPORT;
/*	typedef struct {
		char 	*device_string;
		char	*id;
	} device_name_t;	
	device_name_t device_names[180];
*/
	char **device_names;
	device_names = malloc(181 * sizeof(char*));

	/* Open our device */
	fd = open("/dev/usb/hiddev0", O_RDONLY);

	if (fd < 0) {
		printf("Sorry, cannot open device for reading!\n");
		return -1;
	}

	/* Change the default behavior of read() to yeild hiddev_usage_ref instead */
	if (ioctl(fd, HIDIOCSFLAG, &flag) != 0) {
		printf("Oops, HIDIOCSFLAG failed!\n");
		exit(1);
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

		/* Method 2 (Doesn't work on my 2.6 system) */
		/*
		bytes = hiddev_get_feature_report(fd, 0xB, buffer, REPORT_INPUT_LEN);
        
		if (bytes <= 0)
		{
			free(buffer);
			printf("Oops, this report provided no data!\n");
		} else {
			printf("Success running hiddev_get_feature_report!\n");
			debug_buffer_hex(buffer, REPORT_INPUT_LEN);
		}	
		return 0;	
		*/

		/* Lets set some values in the buffer */
		for (int i=0; i<REPORT_OUTPUT_LEN; i+=2) {
			set_uint16(o_buffer, i, 0x7fff);
		}
		/* software sensor 1 */
		set_uint16(o_buffer, 0, 0x0898);
		/* software sensor 2 */
		set_uint16(o_buffer, 2, 2222);

		printf("\n*** Setting output report:\n"); hiddev_set_report(fd, HID_REPORT_TYPE_OUTPUT, 0x7, o_buffer);
		/* usleep (1000); */

		/* Send report 0x09, then read back report 0x0c 8x for all the device names */
		for (int i=0; i<31; i++) {
			printf("Attempt %d\n", i);
			printf("Sending the following request in report 0x9:\n");
			/* Define the report 9 request */
			/* We need to ensure that the buffer is initialized with 0s for each attempt */
			for (int j=0; j<REPORT_NAME_LEN; j++) {
				rname_buffer[j] = 0;
			}
			
			for (int j=0; j<(REPORT_NAME_LEN * 8); j++) {
				name_buffer[j] = 0;
			}
			set_uint16(rname_buffer, 0, 0x0100);
			set_uint16(rname_buffer, 2, 0x09c0);
			set_uint16(rname_buffer, 4, 0x0000);
			set_uint16(rname_buffer, 6, 0x0010);
			set_uint16(rname_buffer, REPORT_NAME_LEN - 2, 0xdd82);
			/*
			printf("Here is the report 9 before sending:\n");
			debug_buffer_hex(rname_buffer, REPORT_NAME_LEN); */
			hiddev_set_report(fd, HID_REPORT_TYPE_OUTPUT, 0x9, rname_buffer);
			/* usleep(2); */
	
			printf("\n\n** getting the 8x 0xC reports:\n");
			interruptRead(fd, 0xff000001, name_buffer, REPORT_NAME_LEN * 8);
			if (check_and_strip_name_report_watermarks(name_buffer, clean_name_buffer) == 0) {
				printf("watermarks match!\n");
				for (int j=0; j<CLEAN_NAME_LEN; j++) {
					if (((j) % 16 == 0 )) printf("%08X  ", j);
					printf("%02X ", clean_name_buffer[j]);
					if((j+1) % 16 == 0 ) printf( "\n" );
				}
				for (int j=0; j<181; j++) {
					device_names[j] = malloc(23 * sizeof(char));
					/* Copy the non 0 values to the array */
					for (int a=0; a<23; a++) {
						if (a == 22) {
							strncpy(device_names[j] + a, "\0", sizeof(char));
							break;
						}
						else {
							if (clean_name_buffer[(j * 22) + a] != 0) {
								strncpy(device_names[j] + a, clean_name_buffer + (j * 22) + a, sizeof(char));
							} else {
								strncpy(device_names[j] + a, "\0", sizeof(char));
								break;
							}
						}
					}
				}
				break;
			} else {
				if (i == 30) {
					printf("Doh! Failed for the %dth time, bailing out\n", i);
					return -1;
				} else {
					printf("Trying again...\n");
					/* usleep(25000); */
				}
			}
		}

		printf("Printing device names...\n");
		for (int j=0; j<181; j++) {
			printf("%d:%s (%d bytes)\n", j, device_names[j], (int)strlen(device_names[j]));
		}
		/* for (int i=0; i<8; i++) {
			printf("\n%d:\n", i+1); */
		/*	showReport(fd, HID_REPORT_TYPE_INPUT, 0xC, name_buffer); */
		/*	interruptRead(fd, 0xff000001, REPORT_NAME_LEN);
		} */

		return 0;

	} else {
		return -1;
	} 
}

static void set_uint16(unsigned char *buffer, short offset, uint16_t val)
{
	buffer[offset] = val >> 8;
	buffer[offset + 1] = val;
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
	printf("Sending the following in the report:\n");
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
		if (((i) % 16 == 0 )) printf("%08X  ", i);
		printf("%02X ", (__s32)buffer[i]);
		if((i+1) % 16 == 0 ) printf( "\n" );
	}

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
	struct hiddev_usage_ref uref;
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


static void showReport(int fd, unsigned report_type, int report_id, unsigned char *buffer)
{
	struct hiddev_report_info rinfo;
	struct hiddev_field_info finfo;
	struct hiddev_usage_ref uref;
	int j, ret;

	rinfo.report_type = report_type;
	rinfo.report_id = report_id;
	rinfo.num_fields = 1;
	ret = ioctl(fd, HIDIOCGREPORTINFO, &rinfo);
		printf("HIDIOCGREPORTINFO: report_id=0x%X (%u fields)\n",
			rinfo.report_id, rinfo.num_fields);
			finfo.report_type = rinfo.report_type;
			finfo.report_id   = rinfo.report_id;
			finfo.field_index = 0;
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
				uref.field_index = 0;
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
		printf("\n");
}

/* Dumb read function for doing interrupt reads */
static void interruptRead(int fd, unsigned hid, unsigned char *buffer, int len)
{
	struct hiddev_usage_ref uref;
	struct hiddev_usage_ref muref[523];
	int i = 0;
	int j = 0;
	int wrong_reports = 0;
	int flag = HIDDEV_FLAG_UREF | HIDDEV_FLAG_REPORT;

	while(read(fd, &uref, sizeof(struct hiddev_usage_ref)) > 0) {
		if (uref.report_id == 0xc) {
			/*if (uref.field_index == HID_FIELD_INDEX_NONE) { */
				printf("A new report is available. Fetching...\n");
				printf("uref: report_type=%u, report_id=%02X, field_index=%u, usage_index=%u, usage_code=%u, value=%02X, i=%d\n", uref.report_type, uref.report_id, uref.field_index, uref.usage_index, uref.usage_code, uref.value, i);
				if (uref.usage_index != 0) {
					printf("Something is messed up with hiddev right now (uref.usage_index != 0). Attempting reset...\n");
					close(fd);
					
					/* Open our device */
					printf("Reopening the device.\n");
					fd = open("/dev/usb/hiddev0", O_RDONLY);
					if (fd < 0) {
						printf("Sorry, cannot open device for reading!\n");
						exit(1);
					}
					/* Change the default behavior of read() to yeild hiddev_usage_ref instead */
					if (ioctl(fd, HIDIOCSFLAG, &flag) != 0) {
						printf("Oops, HIDIOCSFLAG failed!\n");
						exit(1);
					}

					/* Initing all feature and input reports */
					printf("Initing all input and feature reports.\n");
					if (ioctl(fd, HIDIOCINITREPORT, 0) < 0)
						printf("Failed to init reports!\n");

					/* fsync(fd); */
					/* for (int a=0; a<9; a++) {
						showReport(fd, HID_REPORT_TYPE_INPUT, 0xC, NULL);
						usleep(10000);
					}
					*/
					break;
				}
				/* Read the whole report in quickly */
				/* read(fd, &muref, sizeof(struct hiddev_usage_ref)*523); */
				if (read(fd, &muref, sizeof(struct hiddev_usage_ref) * 523) > 0) { 
					for (j = 0; j<523; j++) {
						/* uref.field_index = 0;
						uref.usage_index = j;
						ioctl(fd, HIDIOCGUCODE, &uref);
						ioctl(fd, HIDIOCGUSAGE, &uref); */
						if (muref[j].report_id != 0xc) {
							printf("We got something other than report 0xC. Breaking and starting over\n");
							i--;
							break;
						}
						buffer[(i*523)+j] = muref[muref[j].usage_index].value;
						/* printf("uref: report_type=%u, report_id=%02X, field_index=%u, usage_index=%u, usage_code=%u, value=%02X, i=%d, j=%d, arrayindex=%d\n", muref[j].report_type, muref[j].report_id, muref[j].field_index, muref[j].usage_index, muref[j].usage_code, muref[j].value, i, j, (i*523)+j); */
					}

					if (i == 7) {
						printf("Last array index was %d\n", (i*523)+j);
						break;
					}
					i++;
				} else {
					printf("Epic read() failure!\n");
					break;
				}
					
			/* } */

			/*	
			printf("uref: report_type=%u, report_id=%02X, field_index=%u, usage_index=%u, usage_code=%u, value=%02X, i=%d\n", uref.report_type, uref.report_id, uref.field_index, uref.usage_index, uref.usage_code, uref.value, i);
			buffer[i] = uref.value;
			if (i == (len - 1)) {
				break;
			}
			i++;
			*/
		} else {
			/* printf("skipping report %02X\n", uref.report_id); */
			if (wrong_reports > 659 ) {
				printf("Too many wrong reports read (%d)! Last array index was %d. Bailing out.\n", wrong_reports, (i*523)+j);
				break;
			}
			wrong_reports++;
		}
	}

	/*
	struct hiddev_event ev;
	int i = 0;
	while(read(fd, &ev, sizeof(struct hiddev_event)) == sizeof(struct hiddev_event)) {

	*/
		/* printf("EV: PARAM %x : %02X\n", ev[i].hid, ev[i].value); */
	/*	if (hid != ev.hid) {
			printf("Oops! We were expecting hid %x and received %x instead!\n", hid, ev.hid);

		}
		buffer[i] = ev.value;

		if (((i) % 16 == 0 )) printf("%08X  ", i);
		printf("%02X ", ev.value);
		if((i+1) % 16 == 0 ) printf( "\n" );
		if (i == (len - 1)) {
			break;
		}
		i++;
	}
	*/
}
