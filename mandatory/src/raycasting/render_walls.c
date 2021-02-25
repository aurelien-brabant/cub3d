/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/25 00:21:40 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "raycasting.h"
#include "img.h"
#include "gfx.h"
#include "misc.h"
#include "libft/core.h"

static void	project_textured_wall(t_ray *ray, t_img *draw_img,
		int wall_height, int wall_top_px)
{
	int		offset[2];
	int		distance_top;
	int		px_per_tex_col;
	int		wall_bot_px;

	wall_bot_px = ft_boundarize(wall_top_px + wall_height, 0,
			draw_img->height - 1);
	px_per_tex_col = TILE_SIZE / ray->tex_img->width;
	if (ray->hit_vert)
		offset[0] = (int)ray->wall_hit[1] % TILE_SIZE / px_per_tex_col;
	else
		offset[0] = ((int)ray->wall_hit[0] % TILE_SIZE) / px_per_tex_col;
	while (wall_top_px < wall_bot_px)
	{
		distance_top = wall_top_px + (wall_height / 2.0)
			- (draw_img->height / 2.0);
		offset[1] = distance_top
			* ((float)ray->tex_img->height / wall_height);
		img_pix_put(draw_img, ray->id, wall_top_px,
				img_pix_get(ray->tex_img, offset[0], offset[1]));
		++wall_top_px;
	}
}

/*
** The project function renders:
** - The textured wall projection
** - The floor and the ceiling colors
*/

static void	project(t_graphics *gfx, t_ray *ray, int *colors)
{
	t_img		*img;
	int			wall_height;
	int			wall_top_px;

	img = &gfx->dpimg;
	wall_height = (TILE_SIZE / ray->wall_dist) * gfx->dist_proj_plane;
	wall_top_px = (img->height / 2.0) - (wall_height / 2.0);
	if (wall_top_px < 0)
		wall_top_px = 0;
	draw_rect(img, (t_rect){ray->id, 0, 1, wall_top_px}, colors[1]);
	project_textured_wall(ray, img, wall_height, wall_top_px);
	draw_rect(img, (t_rect){ray->id, wall_top_px + wall_height,
			1, img->height}, colors[0]);
}

void	render_walls(t_graphics *gfx, int *colors)
{
	t_ray			*ray;
	t_player		*player;
	int				ray_id;

	player = &gfx->player;
	ray_id = 0;
	while (ray_id < gfx->num_rays)
	{
		ray = &gfx->rays[ray_id];
		ray->wall_dist = ray->wall_dist * cos(ray->angle - player->rot_angle);
		if (is_ray_facing_left(ray) && ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_WE - 1];
		else if (is_ray_facing_right(ray) && ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_EA - 1];
		else if (is_ray_facing_bot(ray) && !ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_SO - 1];
		else if (is_ray_facing_top(ray) && !ray->hit_vert)
			ray->tex_img = &gfx->teximg[P_ID_NO - 1];
		project(gfx, ray, colors);
		++ray_id;
	}
}
