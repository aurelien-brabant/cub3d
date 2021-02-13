/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 03:05:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "cub3d_misc.h"
#include "cub3d_gfx.h"

void	render_rays(t_player *player, t_graphics *gfx)
{
	size_t	rayId;
	t_ray	*ray;

	rayId = 0;
	//while (rayId < gfx->num_rays)
	while (rayId < 1)
	{
		ray = &gfx->rays[rayId];
		//printf("%f\n", rad2deg(ray->angle));
		//if (ray->horz_wall_hit[0] != -1)
			//draw_line(&gfx->dpimg[1], (t_line){player->x, player->y, ray->horz_wall_hit[0], ray->horz_wall_hit[1]}, 0xFF0000);
		if (ray->vert_wall_hit[0] != -1)
			draw_line(&gfx->dpimg[1], (t_line){player->x, player->y, ray->vert_wall_hit[0], ray->vert_wall_hit[1]}, 0xFF0000);
		++rayId;
	}
}
