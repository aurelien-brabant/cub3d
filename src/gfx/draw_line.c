/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:07:50 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 15:29:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include "cub3d_gfx.h"

/*
 ** Digital differential analyzer (DDA) line drawing algorithm
 */

/*
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
   */


void	draw_line(t_img *img, t_line line, int color)
{

	int		delta_x;
	int		delta_y;
	char	ix;
	char	iy;
	int		error;

	delta_x = line.x2 - line.x1;
	ix = (delta_x > 0) - (delta_x < 0);
	delta_x = abs(delta_x) << 1;
	delta_y = line.y2 - line.y1;
	iy = (delta_y > 0) - (delta_y < 0);
	delta_y = abs(delta_y) << 1;
	img_pix_put(img, line.x1, line.y1, color);
	if (delta_x >= delta_y)
	{
		error = delta_y - (delta_x >> 1);
		while (line.x1 != line.x2)
		{
			if ((error > 0) || (!error && (ix > 0)))
			{
				error -= delta_x;
				line.y1 += iy;
			}
			error += delta_y;
			line.x1 += ix;
			img_pix_put(img, line.x1, line.y1, color);
		}
	}
	else
	{
		error = delta_x - (delta_y >> 1);
		while (line.y1 != line.y2)
		{
			if ((error > 0) || (!error && (iy > 0)))
			{
				error -= delta_y;
				line.x1 += ix;
			}
			error += delta_x;
			line.y1 += iy;
			img_pix_put(img, line.x1, line.y1, color);
		}
	}
}
