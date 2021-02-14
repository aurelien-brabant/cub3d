/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/14 21:39:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "cub3d_misc.h"
#include "config.h"
#include "cub3d_types.h"

void	render_walls(t_graphics *gfx, t_map_data *mapdat, t_player *player)
{
	int		rayId;
	t_ray	*ray;
	int		wall_height;
	double	ray_distance;
	double	dist_proj_plane;
	int	y;

	rayId = 0;
	while (rayId < gfx->num_rays)
	{
		ray = &gfx->rays[rayId];
		ray_distance = ray->wall_dist * cos(ray->angle - player->rot_angle);
		dist_proj_plane = (mapdat->win_width / 2.0) / tan(gfx->fov / 2.0);
		if (ray_distance == 0)
			wall_height = mapdat->win_height;
		else
			wall_height = (TILE_SIZE / ray_distance) * dist_proj_plane;
		y = ((double)mapdat->win_height / 2) - ((double)wall_height / 2.0);
		printf("%d\n", y);
		if (y < 0)
		{
			y = 0;
			//printf("Negative\n");
		}
		printf("%f\n", y);
		draw_rect(&gfx->dpimg[1], (t_rect){
			rayId * RAY_THICKNESS, y,
			RAY_THICKNESS, wall_height, 0, 0 }, 
			ray->hit_vert ? 0xFFFFFF : 0xEEEEEE);
		++rayId;
	}
}
