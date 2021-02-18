/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 00:27:03 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/18 02:11:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "cub3d_types.h"

/*
** Additional functions dealing with sprites, to make the code
** norm compliant.
*/

static void	draw_sprite_col(t_graphics *gfx, t_sprite *sprite,
		int x, int offset_x)
{
	static const int	transparent_color = 0xFF00FF;
	int					distance_top;
	int					offset_y;
	int					color;
	int					y;

	y = sprite->dy[0];
	if (x < 0 || x >= gfx->dpimg[0].width)
		return ;
	while (y < sprite->dy[1])
	{
		distance_top = y + (sprite->dheight / 2)
			- (gfx->dpimg[1].height / 2.0);
		offset_y = distance_top
			* (gfx->teximg[4].height / sprite->dheight);
		color = img_pix_get(&gfx->teximg[P_ID_S - 1],
				offset_x, offset_y);
		if (color != transparent_color && gfx->rays[x].wall_dist
			> sprite->distance)
			img_pix_put(&gfx->dpimg[1], x, y, color);
		++y;
	}
}

static void	draw_sprite_row(t_graphics *gfx, t_sprite *sprite)
{
	int		x;
	int		offset_x;
	t_img	*tex;

	tex = &gfx->teximg[4];
	x = sprite->dx[0];
	while (x < sprite->dx[1])
	{
		offset_x = (x - (int)sprite->dx[0]) * (tex->width / sprite->dwidth);
		draw_sprite_col(gfx, sprite, x, offset_x);
		++x;
	}
}

/*
** Do most of the required computations
** Used in a ft_vec_foreach context.
*/

int	draw_sprite(t_sprite *sprite, size_t i, t_cub3d *c3d)
{
	t_img		*draw_img;
	t_player	*player;
	double		sprite_angle;

	(void)i;
	player = &c3d->gamedat.player;
	draw_img = &c3d->gfx.dpimg[1];
	sprite->dheight = (TILE_SIZE / sprite->distance) * c3d->gfx.dist_proj_plane;
	sprite->dwidth = sprite->dheight;
	sprite->dy[0] = (draw_img->height / 2.0) - (sprite->dheight / 2.0);
	if (sprite->dy[0] < 0)
		sprite->dy[0] = 0;
	sprite->dy[1] = (draw_img->height / 2.0) + (sprite->dheight / 2.0);
	if (sprite->dy[1] >= draw_img->width)
		sprite->dy[1] = draw_img->width;
	sprite_angle = atan2(sprite->y - player->y, sprite->x - player->x)
		- player->rot_angle;
	sprite->dx[0] = (draw_img->width / 2.0) + tan(sprite_angle)
		* c3d->gfx.dist_proj_plane - (sprite->dwidth / 2);
	sprite->dx[1] = sprite->dx[0] + sprite->dwidth;
	draw_sprite_row(&c3d->gfx, sprite);
	return (0);
}
