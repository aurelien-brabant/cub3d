/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:32:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/21 22:15:03 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_gfx.h"

void	render_aim(t_graphics *gfx)
{
	int	mid_height;
	int	mid_width;
	int	x;
	int	y;
	int	len;

	len = 1.0 * (gfx->win_width / 100.0);
	mid_width = gfx->win_width / 2.0;
	mid_height = gfx->win_height / 2.0;
	y = mid_height - len;
	while (y < mid_height + len)
		img_pix_put(&gfx->dpimg, mid_width, y++, 0xFFFF);
	x = mid_width - len;
	while (x < mid_width + len)
		img_pix_put(&gfx->dpimg, x++, mid_height, 0xFFFF);
}
