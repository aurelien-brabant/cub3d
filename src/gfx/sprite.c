/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:26:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/18 02:08:49 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft/vector.h"
#include "libft/core.h"

#include "cub3d_gfx.h"

/*
** Determines if a sprite is visible or not.
** If it is, add it to the visible_sprites vector and calculate its distance
** from the player as well as the angle formed between the player and the
** sprite.
*/

static int	put_visible_sprite(t_sprite *sprite, size_t index, t_cub3d *c3d)
{
	static const double	epsilon = 0.2;
	t_player			*player;
	double				angle_sprite_player;

	(void)index;
	player = &c3d->gamedat.player;
	angle_sprite_player = player->rot_angle - atan2(sprite->y - player->y,
			sprite->x - player->x);
	if (angle_sprite_player > M_PI)
		angle_sprite_player -= M_PI * 2;
	else if (angle_sprite_player < -M_PI)
		angle_sprite_player += M_PI * 2;
	angle_sprite_player = fabs(angle_sprite_player);
	if (angle_sprite_player < (c3d->gfx.fov / 2.0) + epsilon)
	{
		sprite->angle = angle_sprite_player;
		sprite->distance = get_points_dist(sprite->x, sprite->y,
				player->x, player->y) * cos(sprite->angle);
		ft_vec_add(c3d->gfx.visible_sprites, sprite);
	}
	return (0);
}

/*
** Compare sprites by distance
*/

static int	comp_sprites(void *el1, void *el2)
{
	return ((*(t_sprite **)el2)->distance - (*(t_sprite **)el1)->distance);
}

void	render_sprite_projection(t_cub3d *c3d)
{
	ft_vec_set_len(c3d->gfx.visible_sprites, 0);
	ft_vec_foreach(c3d->gfx.sprites, &put_visible_sprite, c3d);
	ft_vec_sort(c3d->gfx.visible_sprites, &ft_bsort, &comp_sprites);
	ft_vec_foreach(c3d->gfx.visible_sprites, &draw_sprite, c3d);
}
