/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 19:26:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 09:43:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_types.h"
#include "gfx.h"
#include "raycasting.h"
#include "libft/vector.h"
#include "libft/core.h"

/*
** Determines if a sprite is visible or not.
** If it is, add it to the visible_sprites vector and calculate its distance
** from the player as well as the angle formed between the player and the
** sprite.
** The epsilon constant is used to ensure smooth appearance/disappearance
** of the sprites when the player rotates.
*/

static int	put_visible_sprite(t_sprite *sprite, size_t index, t_cub3d *c3d)
{
	static const double	epsilon = 0.2;
	t_player			*player;
	double				angle_sprite_player;

	(void)index;
	player = &c3d->gfx.player;
	angle_sprite_player = player->rot_angle - atan2(sprite->pos.y
			- player->pos.y, sprite->pos.x - player->pos.x);
	if (angle_sprite_player > M_PI)
		angle_sprite_player -= M_PI * 2;
	else if (angle_sprite_player < -M_PI)
		angle_sprite_player += M_PI * 2;
	angle_sprite_player = fabs(angle_sprite_player);
	if (angle_sprite_player < (c3d->gfx.fov / 2.0) + epsilon)
	{
		sprite->angle = angle_sprite_player;
		sprite->distance = get_points_dist(sprite->pos.x, sprite->pos.y,
				player->pos.x, player->pos.y) * cos(sprite->angle);
		ft_vec_add(c3d->gfx.visible_sprites, sprite);
	}
	return (0);
}

/*
** Compare sprites by distance. Used to compare two sprites using ft_vec_sort.
*/

static int	comp_sprites(void *el1, void *el2)
{
	return ((*(t_sprite **)el2)->distance - (*(t_sprite **)el1)->distance);
}

void	draw_sprite_projection(t_cub3d *c3d)
{
	ft_vec_set_len(c3d->gfx.visible_sprites, 0);
	ft_vec_foreach(c3d->gfx.sprites, &put_visible_sprite, c3d);
	ft_vec_sort(c3d->gfx.visible_sprites, &ft_quick_sort, &comp_sprites);
	ft_vec_foreach(c3d->gfx.visible_sprites, &draw_sprite, c3d);
}
