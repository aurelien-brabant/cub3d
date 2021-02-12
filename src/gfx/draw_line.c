/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:07:50 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 02:18:41 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_gfx.h"

static void	swap_coords(t_line *line)
{
	int tmp;

	tmp = line->x1;
	line->x1 = line->x2;
	line->x2 = tmp;
	tmp = line->y1;
	line->y1 = line->y2;
	line->y2 = tmp;
}

void	draw_line(t_img *img, t_line line, int color)
{
	int	distX;
	int	distY;
	int decision;
	int nextX;
	int nextY;

	if (line.x1 > line.x2 || line.y1 > line.y2)
		swap_coords(&line);
	distX = line.x2 - line.x1;
	distY = line.y2 - line.y1;
	decision = 2 * distY - distX;
	nextX = line.x1;
	nextY = line.y1;
	img_pix_put(img, nextX, nextY, color);
	while (nextX != line.x2 && nextY != line.y2 )
	{
		if (decision < 0)
			decision += 2 * distY;
		else
		{
			decision += 2 * distY - 2 * distX;
			++nextY;
		}
		++nextX;
		img_pix_put(img, nextX, nextY, color);
	}
}
