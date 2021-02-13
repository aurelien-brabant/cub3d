/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 18:54:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "cub3d_misc.h"
#include "config.h"
#include "cub3d_types.h"

void	render_walls(t_graphics *gfx, t_map_data *mapdat, t_player *player)
{
	size_t	rayId;
	t_ray	*ray;
	double	wall_height;
	double	ray_distance;
	double	dist_proj_plane;
	int		y;

	rayId = 0;
	while (rayId < gfx->num_rays)
	{
		ray = &gfx->rays[rayId];
		ray_distance = ray->wall_dist * cos(ray->angle - player->rot_angle);
		dist_proj_plane = (mapdat->win_width / 2.0) / tan(deg2rad(FOV_ANGLE / 2.0));
		wall_height = (TILE_SIZE / ray_distance) * dist_proj_plane;
		y = (mapdat->win_height / 2.0) - (wall_height / 2.0);
		if (y < 0)
			y = 0;
		draw_rect(&gfx->dpimg[1], (t_rect){
			rayId, y,
			1, wall_height, 0, 0 }, 
			ray->hit_vert ? 0xFFFFFF : 0xEEEEEE);
		++rayId;
	}
}
