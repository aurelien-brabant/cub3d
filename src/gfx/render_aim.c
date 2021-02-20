/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:32:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/20 21:13:57 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_gfx.h"

void	render_aim(t_graphics *gfx)
{
	int mid_height;
	int	mid_width;
	int	x;
	int y;

	mid_width = gfx->dpimg[1].width / 2.0;
	mid_height = gfx->dpimg[1].height / 2.0;

	y = mid_height - 10;
	while (y < mid_height + 10)
		img_pix_put(&gfx->dpimg[1], mid_width, y++, 0xFFFF);
	x = mid_width - 10;
	while (x < mid_width + 10)
		img_pix_put(&gfx->dpimg[1], x++, mid_height, 0xFFFF);
}
