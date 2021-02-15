/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/15 02:38:58 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "cub3d_misc.h"
#include "config.h"
#include "cub3d_types.h"

static void	project_wall(t_graphics *gfx, t_ray *ray, int ray_id, int *colors)
{
	t_img	*drawing_img;
	int		wall_height;
	int		wall_top_px;

	drawing_img = &gfx->dpimg[1];
	wall_height = (TILE_SIZE / ray->wall_dist) * gfx->dist_proj_plane;
	wall_top_px = (drawing_img->height / 2.0) - (wall_height / 2.0);
	if (wall_top_px < 0)
		wall_top_px = 0;
	draw_rect(&gfx->dpimg[1], (t_rect){ray_id * RAY_THICKNESS, 0,
			RAY_THICKNESS, wall_top_px, 0, 0 }, colors[1]);
	/*draw_rect(&gfx->dpimg[1], (t_rect){ray_id * RAY_THICKNESS, wall_top_px,
			RAY_THICKNESS, wall_height, 0, 0 }, !ray->hit_vert ? 0xFFFFFF : 0xEEEEEE);
	*/
	draw_rect(&gfx->dpimg[1], (t_rect){ray_id * RAY_THICKNESS,
			wall_top_px + wall_height, RAY_THICKNESS, drawing_img->height,
			0, 0 }, colors[0]);
}

/*
void	tell_orientation(t_ray *ray)
{
	if (ray->facing_left && ray->hit_vert)
		puts("West\n");
	if (!ray->facing_left && ray->hit_vert)
		puts("East");
	if (ray->facing_down && !ray->hit_vert)
		puts("South\n");
	if (!ray->facing_down && !ray->hit_vert)
		puts("North\n");
}
*/

void	render_walls(t_graphics *gfx, t_map_data *mapdat, t_player *player)
{
	t_ray	*ray;
	int		ray_id;

	ray_id = 0;
	while (ray_id < gfx->num_rays)
	{
		ray = &gfx->rays[ray_id];
		ray->wall_dist = ray->wall_dist * cos(ray->angle - player->rot_angle);
		project_wall(gfx, ray, ray_id, mapdat->col);
		++ray_id;
	}
}
