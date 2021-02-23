/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_int_rev_buf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:41:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 21:56:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

void	bmp_int_rev_buf(t_bmp *bmp, uint8_t *buf)
{
	uint32_t	start;
	uint32_t	end;
	uint8_t		tmp;
	uint32_t	i;
	uint32_t	rowlen;

	start = bmp->file_header.pixel_data_offset;
	end = bmp->file_header.file_size;
	rowlen = bmp->file_info.img_width * (bmp->file_info.bpp / 8);
	while (start < end)
	{
		i = 0;
		while (i < rowlen)
		{
			tmp = buf[start + i];
			buf[start + i] = buf[end - (rowlen - i)];
			buf[end - (rowlen - i)] = tmp;
			++i;
		}
		start += rowlen;
		end -= rowlen;
	}
}
