/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:36:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raycasting.h"
#include "img.h"
#include "gfx.h"
#include "misc.h"
#include "libft/core.h"

static void	project_textured_wall(t_ray *ray, t_img *img, double wall_height,
		int wall_top_px)
{
	t_coords	offset;
	int			distance_top;
	int			px_per_tex_col;
	int			wall_bot_px;

	wall_bot_px = wall_top_px + wall_height;
	if (wall_bot_px > img->height)
		wall_bot_px = img->height;
	px_per_tex_col = TILE_SIZE / ray->tex_img->width;
	if (ray->was_hit_vert)
		offset.x = (int)ray->hit.y % TILE_SIZE / px_per_tex_col;
	else
		offset.x = ((int)ray->hit.x % TILE_SIZE) / px_per_tex_col;
	while (wall_top_px < wall_bot_px)
	{
		distance_top = wall_top_px + (wall_height / 2.0)
			- (img->height / 2.0);
		offset.y = distance_top
			* ((double)ray->tex_img->height / wall_height);
		img_pix_put(img, ray->id, wall_top_px,
				img_pix_get(ray->tex_img, offset.x, offset.y));
		++wall_top_px;
	}
}

static void	draw_ceiling(t_img *img, int ray_id, int wall_top_px, int color)
{
	int	pixy;

	pixy = 0;
	while (pixy < wall_top_px)
		img_pix_put(img, ray_id, pixy++, color);
}

static void	draw_floor(t_img *img, int ray_id, int wall_bot_px, int color)
{
	int	pixy;

	pixy = wall_bot_px;
	while (pixy < img->height)
		img_pix_put(img, ray_id, pixy++, color);
}

/*
** The project function renders:
** - The textured wall projection
** - The floor and the ceiling colors
*/

static void	project(t_graphics *gfx, t_ray *ray, int *colors)
{
	t_img		*img;
	double		wall_height;
	int			wall_top_px;

	img = &gfx->dpimg;
	wall_height = (TILE_SIZE / ray->dist) * gfx->dist_proj_plane;
	wall_top_px = (img->height / 2.0) - (wall_height / 2.0);
	if (wall_top_px < 0)
		wall_top_px = 0;
	draw_ceiling(img, ray->id, wall_top_px, colors[1]);
	project_textured_wall(ray, img, wall_height, wall_top_px);
	draw_floor(img, ray->id, wall_top_px + wall_height, colors[0]);
}

void	draw_walls(t_graphics *gfx, int *colors)
{
	t_ray			*ray;
	t_player		*player;
	int				ray_id;

	player = &gfx->player;
	ray_id = 0;
	while (ray_id < gfx->num_rays)
	{
		ray = &gfx->rays[ray_id];
		ray->dist = ray->dist * cos(ray->angle - player->rot_angle);
		if (is_ray_facing_left(ray) && ray->was_hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_WE - 1];
		else if (is_ray_facing_right(ray) && ray->was_hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_EA - 1];
		else if (is_ray_facing_bot(ray) && !ray->was_hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_SO - 1];
		else if (is_ray_facing_top(ray) && !ray->was_hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_NO - 1];
		project(gfx, ray, colors);
		++ray_id;
	}
}
