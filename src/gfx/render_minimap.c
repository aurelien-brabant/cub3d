/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:05:26 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 16:56:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "cub3d_gfx.h"

#include "libft/string.h"

static int	get_color(const unsigned char c)
{
	if (c == '1')
		return (0xFF0000);
	return (0xFFFFFF);
}

static t_rect	get_rect(size_t x, size_t y)
{
	t_rect	rect;

	rect.x = x * TILE_SIZE * MINIMAP_FACTOR;
	rect.y = y * TILE_SIZE * MINIMAP_FACTOR;
	rect.width = TILE_SIZE * MINIMAP_FACTOR;
	rect.height = TILE_SIZE * MINIMAP_FACTOR;
	rect.border_size = 1;
	rect.border_color = 0x0;
	return (rect);
}

void	render_minimap(t_vector map, t_img *img)
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
