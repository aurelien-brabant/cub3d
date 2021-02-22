#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

static const uint32_t data[] = {
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000,
};

static const int	width = 6;
static const int	height = 2;
static const int	bpp = 32;

void	pix_fn(uint8_t *stream, uint8_t *bytes)
{
	bytes[0] = stream[0];
	bytes[1] = stream[1];
	bytes[2] = stream[2];
	bytes[3] = stream[3];
	printf("bytes: %x\n", *(uint32_t *)bytes);
}

int main(void)
{
	t_bmp	*bmp;

	bmp = bmp_new((uint8_t *)data, width, height, bpp);
	if (bmp == NULL)
	{
		puts("Failed to initialize bmp object");
		return (1);
	}
	bmp_encode_file(bmp, "pic.bmp", &pix_fn, BMP_EM_REVERSE);
	free(bmp);
	return (0);
}
