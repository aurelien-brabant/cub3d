/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:27:32 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 17:04:44 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d_gfx.h"

static int	is_border(t_rect rect, int x, int y)
{
	int	finalX;
	int finalY;

	finalX = rect.x + rect.width;
	finalY = rect.y + rect.height;

	return (
		(x >= 0 && x < rect.border_size)
		|| (x >= finalX - rect.border_size)
		|| (y >= 0 && y < rect.border_size)
		|| (y >= finalY - rect.border_size)
	);
}

void	draw_rect(t_img *img, t_rect rect, int color)
{
	int i;
	int j;

	i = rect.y;
	while (i < img->height && i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < img->width && j < rect.x + rect.width)
		{
			if (is_border(rect, j, i))
				img_pix_put(img, j++, i, rect.border_color);
			else
				img_pix_put(img, j++, i, color);
		}
		++i;
	}
}
