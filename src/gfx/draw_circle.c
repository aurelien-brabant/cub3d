/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:21:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 17:44:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"

void	draw_circle(t_img *img, int x, int y, int radius)
{
	double	angle;

	angle = 0 * (M_PI / 180);
	while (angle <= M_PI * 2)
	{
		draw_line(img, (t_line){x, y, x + cos(angle) * radius, y + sin(angle) * radius}, 0xFF00);
		angle += 1 * (M_PI / 180);
	}
}
