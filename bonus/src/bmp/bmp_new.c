/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelienbrabant <marvin@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:21:24 by aurelienb         #+#    #+#             */
/*   Updated: 2021/02/21 11:26:29 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "bmp.h"

/*
 ** Some elements are not set as they would be set to zero,
 ** and calloc already did the job when it initialized the
 ** memory.
 */

static void	init_file_info_header(t_bmp *bmp, int width, int height, int bpp)
{
	bmp->file_info.header_size = BITMAP_INFO_HEADER_SIZE;
	bmp->file_info.img_width = width;
	bmp->file_info.img_height = height;
	bmp->file_info.planes = 1;
	bmp->file_info.bpp = bpp;
}

t_bmp	*bmp_new(uint8_t *stream, int width, int height, int bpp)
{
	t_bmp	*bmp;
	size_t	rowlen;

	bmp = calloc(1, sizeof (*bmp));
	if (bmp == NULL)
		return (NULL);
	bmp->stream = stream;
	bmp->file_header.file_type = 0x4d << 8 | 0x42;
	init_file_info_header(bmp, width, height, bpp);
	rowlen = bmp->file_info.img_width * (bmp->file_info.bpp / 8);
	while (rowlen % 4 != 0)
		++rowlen;
	bmp->file_header.pixel_data_offset = BITMAP_FILE_HEADER_SIZE
		+ BITMAP_INFO_HEADER_SIZE;
	bmp->file_header.file_size = bmp->file_header.pixel_data_offset
		+ rowlen * bmp->file_info.img_height;
	return (bmp);
}
