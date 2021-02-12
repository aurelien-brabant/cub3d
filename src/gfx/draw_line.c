/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:07:50 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 16:12:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <stdio.h>
#include "cub3d_gfx.h"

/*
** Digital differential analyzer (DDA) line drawing algorithm
*/

void	draw_line(t_img *img, t_line line, int color)
{
	double	distX;
	double	distY;
	double	step;
	double	coords[2];
	int		i;

	distX = line.x2 - line.x1;
	distY = line.y2 - line.y1;
	if (fabs(distX) >= fabs(distY))
		step = fabs(distX);
	else
		step = fabs(distY);
	distX /= step;
	distY /= step;
	coords[0] = line.x1;
	coords[1] = line.y1;
	i = 1;
	while (i <= step)
	{
		img_pix_put(img, coords[0], coords[1], color);
		coords[0] += distX;
		coords[1] += distY;
		++i;
	}
}
