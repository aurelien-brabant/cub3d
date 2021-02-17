/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:26:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/17 03:41:23 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "libft/vector.h"

#include "cub3d_types.h"

static int	put_visible_sprite(t_sprite *sprite, size_t index, t_cub3d *c3d)
{
	t_player	*player;
	double		angle_sprite_player;

	(void)index;
	player = &c3d->gamedat.player;
	angle_sprite_player = player->rot_angle - atan2(sprite->y - player->y,
			sprite->x - player->x);
	if (angle_sprite_player > M_PI)
		angle_sprite_player -= M_PI * 2;
	else if (angle_sprite_player < -M_PI)
		angle_sprite_player += M_PI * 2;
	angle_sprite_player = fabs(angle_sprite_player);
	//printf("%f - (%f)\n", rad2deg(player->rot_angle), rad2deg(atan2(sprite->y - player->y, sprite->x - player->x)));
	if (angle_sprite_player < (c3d->gfx.fov / 2.0))
	{
		ft_vec_add(c3d->gfx.visible_sprites, sprite);
	}
	return (0);
}

static int	print(t_sprite *sprite)
{
	printf("VISIBLE SPRITE: (%f; %f)\n", sprite->x, sprite->y);
	return (0);
}

static int	put_pixel(t_sprite *sprite, size_t i, t_img *img)
{
	img_pix_put(img, sprite->x * MINIMAP_FACTOR, sprite->y * MINIMAP_FACTOR, 0xFF0000);
	return (0);
}

static int	put_pixel2(t_sprite *sprite, size_t i, t_img *img)
{
	img_pix_put(img, sprite->x * MINIMAP_FACTOR, sprite->y * MINIMAP_FACTOR, 0xFF);
	return (0);
}

void	render_sprite_minimap(t_cub3d *c3d)
{
	ft_vec_foreach(c3d->gfx.sprites, &put_pixel, &c3d->gfx.dpimg[1]);
	ft_vec_foreach(c3d->gfx.visible_sprites, &put_pixel2, &c3d->gfx.dpimg[1]);
}

void	render_sprite_projection(t_cub3d *c3d)
{
	//get_visible_sprites(gfx->sprites, gfx->visible_sprites, player);
	ft_vec_set_len(c3d->gfx.visible_sprites, 0);
	ft_vec_foreach(c3d->gfx.sprites, &put_visible_sprite, c3d);
	ft_vec_foreach(c3d->gfx.visible_sprites, &print, NULL);
}
