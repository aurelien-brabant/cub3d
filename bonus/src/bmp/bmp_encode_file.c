/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_encode_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 21:30:23 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 22:36:23 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "bmp.h"

static void	write_buf(uint8_t **buf, uint8_t *data, int n)
{
	while (n-- > 0)
	{
		**buf = *data++;
		*buf += 1;
	}
}

static void	write_pixels(t_bmp *bmp, uint8_t **buf,
		void (*pix_fn)(uint8_t *, uint8_t *, int))
{
	uint8_t		bytes[4];
	uint32_t	i;
	uint32_t	j;
	uint32_t	rowlen;
	uint8_t		bytes_per_pixel;

	bytes_per_pixel = bmp->file_info.bpp / 8;
	rowlen = bmp->file_info.img_width * (bytes_per_pixel);
	i = 0;
	while (i < bmp->file_info.img_height)
	{
		j = 0;
		while (j < rowlen)
		{
			pix_fn(&bmp->stream[i * rowlen + j], bytes, bmp->file_info.bpp);
			write_buf(buf, bytes, bytes_per_pixel);
			j += bytes_per_pixel;
		}
		while (j++ % 4 != 0)
			write_buf(buf, (uint8_t *) "\x0", 1);
		++i;
	}
}

static void	write_header(t_bmp *bpm, uint8_t **buf)
{
	write_buf(buf, (uint8_t *)&bpm->file_header.file_type, 2);
	write_buf(buf, (uint8_t *)&bpm->file_header.file_size, 4);
	write_buf(buf, (uint8_t *)&bpm->file_header.reserved1, 2);
	write_buf(buf, (uint8_t *)&bpm->file_header.reserved2, 2);
	write_buf(buf, (uint8_t *)&bpm->file_header.pixel_data_offset, 4);
}

static void	write_info(t_bmp *bpm, uint8_t **buf)
{
	write_buf(buf, (uint8_t *)&bpm->file_info.header_size, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.img_width, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.img_height, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.planes, 2);
	write_buf(buf, (uint8_t *)&bpm->file_info.bpp, 2);
	write_buf(buf, (uint8_t *)&bpm->file_info.compression, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.img_size, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.xppm, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.yppm, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.total_colors, 4);
	write_buf(buf, (uint8_t *)&bpm->file_info.imp_colors, 4);
}

int	bmp_encode_file(t_bmp	*bmp, const char *path,
		void (*pix_fn)(uint8_t *, uint8_t *, int), t_encode_mode mode)
{		
	uint8_t	*buf;
	int		fd;
	int		bmp_size;

	bmp_size = bmp->file_header.file_size;
	buf = calloc(bmp->file_header.file_size, sizeof(uint8_t));
	if (buf == NULL)
		return (0);
	fd = open(path, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (fd == -1)
		return (0);
	write_header(bmp, &buf);
	write_info(bmp, &buf);
	write_pixels(bmp, &buf, pix_fn);
	buf -= bmp_size;
	if (mode & BMP_EM_REVERSE)
		bmp_int_rev_buf(bmp, buf);
	write(fd, buf, bmp_size);
	free(buf);
	return (1);
}
