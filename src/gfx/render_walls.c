/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/15 18:49:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "cub3d_misc.h"
#include "config.h"
#include "cub3d_types.h"

int		wall_height;

static void	project_textured_wall(t_ray *ray, t_img *draw_img, int wall_top_px, int wall_bot_px)
{
	int	y;
	int	offset_x;
	int offset_y;
	int distance_top;

	if (ray->hit_vert)
		offset_x = (int)ray->wall_hit[1] % TILE_SIZE; 
	else
		offset_x = (int)ray->wall_hit[0] % TILE_SIZE; 
	y = wall_top_px;
	while (y < wall_bot_px)
	{
		distance_top = y + ((double)wall_height / 2) - ((double)draw_img->height / 2);
		offset_y = distance_top * ((double)ray->tex_img->height / (wall_height));
		img_pix_put(draw_img, ray->id, y, img_pix_get(ray->tex_img, offset_x, offset_y));
		++y;
	}
}

static void	project_wall(t_graphics *gfx, t_ray *ray, int *colors)
{
	t_img	*drawing_img;
	int		wall_top_px;
	int		wall_bot_px;

	drawing_img = &gfx->dpimg[1];
	wall_height = (TILE_SIZE / ray->wall_dist) * gfx->dist_proj_plane;
	wall_top_px = (drawing_img->height / 2.0) - (wall_height / 2.0);
	wall_bot_px = wall_top_px + wall_height;
	if (wall_top_px < 0)
		wall_top_px = 0;
	if (wall_bot_px > drawing_img->height)
		wall_bot_px = drawing_img->height;
	draw_rect(&gfx->dpimg[1], (t_rect){ray->id * RAY_THICKNESS, 0,
			RAY_THICKNESS, wall_top_px, 0, 0 }, colors[1]);
	project_textured_wall(ray, drawing_img, wall_top_px, wall_bot_px);
	/*draw_rect(&gfx->dpimg[1], (t_rect){ray_id * RAY_THICKNESS, wall_top_px,
	  RAY_THICKNESS, wall_height, 0, 0 }, !ray->hit_vert ? 0xFFFFFF : 0xEEEEEE);
	  */
	draw_rect(&gfx->dpimg[1], (t_rect){ray->id * RAY_THICKNESS,
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
		if (ray->facing_left && ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_WE - 1];
		else if (!ray->facing_left && ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_EA - 1];
		else if (ray->facing_down && !ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_SO - 1];
		else if (!ray->facing_down && !ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_NO - 1];
		project_wall(gfx, ray, mapdat->col);
		++ray_id;
	}
}
