/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:58:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 09:41:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Additional functions dealing with sprites, to make the code
** norm compliant.
*/

#include <math.h>
#include <stdio.h>

#include "misc.h"
#include "img.h"
#include "raycasting.h"
#include "libft/core.h"

static void	draw_sprite_col(t_graphics *gfx, t_sprite *sprite,
		int x, int offset_x)
{
	static const int	transparent_color = 0xFF00FF;
	int					distance_top;
	int					offset_y;
	int					y;
	int					color;

	y = sprite->dpy_start;
	if (x < 0 || x >= gfx->dpimg.width)
		return ;
	while (y < sprite->dpy_end)
	{
		distance_top = y + (sprite->dpheight / 2.0) - (gfx->dpimg.height / 2.0);
		offset_y = distance_top * (gfx->teximg[4].height / sprite->dpheight);
		offset_y = ft_clamp(offset_y, 0, gfx->teximg[4].height - 1);
		color = img_pix_get(&gfx->teximg[P_ID_S - 1], offset_x, offset_y);
		if (color != transparent_color && gfx->rays[x].dist > sprite->distance)
			img_pix_put(&gfx->dpimg, x, y, color);
		++y;
	}
}

/*
** NOTE:
** *x* needs to store enough precision in order to get the proper and 
** non-negative offset_x. It will be implicitely converted to int
** in the draw_sprite_col function.
*/

static void	draw_sprite_row(t_graphics *gfx, t_sprite *sprite)
{
	int				x;
	int				offset_x;
	t_img			*tex;

	tex = &gfx->teximg[4];
	x = sprite->dpx_start;
	while (x < sprite->dpx_end)
	{
		offset_x = (x - sprite->dpx_start) * (tex->width / sprite->dpwidth);
		offset_x = ft_clamp(offset_x, 0, tex->width - 1);
		if (offset_x < 0)
			offset_x = 0;
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
	t_img		*img;
	t_player	*player;
	double		sprite_angle;

	(void)i;
	player = &c3d->gfx.player;
	img = &c3d->gfx.dpimg;
	sprite->dpheight = (TILE_SIZE / sprite->distance) * c3d->gfx.dist_proj_plane;
	sprite->dpwidth = sprite->dpheight;
	sprite->dpy_start = ft_clamp((img->height / 2.0)
			- (sprite->dpheight / 2.0), 0, img->height - 1);
	sprite->dpy_end = ft_clamp((img->height / 2.0)
			+ (sprite->dpheight / 2.0), 0, img->height - 1);
	sprite_angle = atan2(sprite->pos.y - player->pos.y,
			sprite->pos.x - player->pos.x) - player->rot_angle;
	sprite->dpx_start = (img->width / 2.0) + tan(sprite_angle)
		* c3d->gfx.dist_proj_plane - (sprite->dpwidth / 2.0);
	sprite->dpx_end = sprite->dpx_start + sprite->dpwidth;
	draw_sprite_row(&c3d->gfx, sprite);
	return (0);
}
