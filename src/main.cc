#include <stdio.h>
#include <stdlib.h>

#include "test.h"

void leak_test()
{
    char *tmp;

    tmp = (char*)malloc(100);
    tmp[0] = '1';
}

int main(int argc, char *argv[])
{
	EpdParam epd_param;

    leak_test();

	if (kwd_initialize("/", "/") < 0)
	{
		printf("failed\n");
		return -1;
	}

	epd_param.input_type = EPD_DATA_TYPE_LINEAR_PCM16;
	epd_param.output_type = EPD_DATA_TYPE_SPEEX_STREAM;

	if (epd_client_start("/", epd_param) < 0)
	{
		printf("failed\n");
		return -1;
	}

	kwd_deinitialize();

	return 0;
}
