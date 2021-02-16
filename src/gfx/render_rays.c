/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/16 01:44:42 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "cub3d_misc.h"
#include "cub3d_gfx.h"

void	render_rays(t_player *player, t_graphics *gfx)
{
	int		ray_id;
	t_ray	*ray;

	ray_id = 0;
	while (ray_id < gfx->num_rays)
	//while (ray_id < 1)
	{
		ray = &gfx->rays[ray_id];
		//printf("%f\n", rad2deg(ray->angle));
		draw_line(&gfx->dpimg[1], (t_line){player->x * MINIMAP_FACTOR, 
				player->y * MINIMAP_FACTOR, ray->wall_hit[0] * MINIMAP_FACTOR, ray->wall_hit[1] * MINIMAP_FACTOR}, 0xFF00);
		//draw_line(&gfx->dpimg[1], (t_line){player->x, player->y, player->x + cos(ray->angle) * 30, player->y  + sin(ray->angle) * 30}, 0xFF);
		++ray_id;
	}
}
