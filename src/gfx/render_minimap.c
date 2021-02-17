/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:05:26 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/17 03:23:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "config.h"
#include "cub3d_gfx.h"

#include "libft/string.h"

static int	get_color(const unsigned char c)
{
	if (c == '1')
		return (0xFF0000);
	if (c == ' ')
		return (0x0);
	return (0xFFFFFF);
}

static t_rect	get_rect(size_t x, size_t y)
{
	t_rect	rect;

	rect.x = x * (int)(TILE_SIZE * MINIMAP_FACTOR);
	rect.y = y * (int)(TILE_SIZE * MINIMAP_FACTOR);
	rect.width = (int)(TILE_SIZE * MINIMAP_FACTOR);
	rect.height = (int)(TILE_SIZE * MINIMAP_FACTOR);
	rect.border_size = 1;
	rect.border_color = 0x0;
	return (rect);
}

void	render_minimap(t_cub3d *c3d, t_vector map, t_img *img)
{
	const unsigned char	*row;
	size_t				x;
	size_t				y;
	size_t				rowlen;

	y = 0;
	while (y < ft_vec_len(map))
	{
		row = ft_vec_get(map, y);
		rowlen = ft_strlen((const char *)row);
		x = 0;
		while (x < rowlen)
		{
			draw_rect(img, get_rect(x, y), get_color(row[x]));
			++x;
		}
		++y;
	}
}
