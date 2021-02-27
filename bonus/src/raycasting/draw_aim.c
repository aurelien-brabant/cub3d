/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:32:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 02:33:16 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img.h"

void	draw_aim(t_graphics *gfx)
{
	int	mid_height;
	int	mid_width;
	int	x;
	int	y;
	int	len;

	len = 1.2 * (gfx->win_height / 100.0);
	mid_width = gfx->win_width / 2.0;
	mid_height = gfx->win_height / 2.0;
	y = mid_height - len;
	while (y < mid_height + len)
		img_pix_put(&gfx->dpimg, mid_width, y++, 0xFFFFFF);
	x = mid_width - len;
	while (x < mid_width + len)
		img_pix_put(&gfx->dpimg, x++, mid_height, 0xFFFFFF);
}
