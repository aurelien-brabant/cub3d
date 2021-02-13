/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 18:42:35 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "config.h"
#include "cub3d_misc.h"
#include "cub3d_gfx.h"

void	render_rays(t_player *player, t_graphics *gfx)
{
	size_t	rayId;
	t_ray	*ray;

	rayId = 0;
	while (rayId < gfx->num_rays)
	//while (rayId < 1)
	{
		ray = &gfx->rays[rayId];
		//printf("%f\n", rad2deg(ray->angle));
		draw_line(&gfx->dpimg[1], (t_line){player->x * MINIMAP_FACTOR, 
				player->y * MINIMAP_FACTOR, ray->wall_hit[0] * MINIMAP_FACTOR, ray->wall_hit[1] * MINIMAP_FACTOR}, 0xFF00);
		//draw_line(&gfx->dpimg[1], (t_line){player->x, player->y, player->x + cos(ray->angle) * 30, player->y  + sin(ray->angle) * 30}, 0xFF);
		++rayId;
	}
}
