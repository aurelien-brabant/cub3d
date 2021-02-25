/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:45:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/25 00:41:41 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "config.h"
#include "gfx.h"
#include "misc.h"
#include "raycasting.h"
#include "libft/vector.h"

static void	update_player(t_vector *map, t_player *player)
{
	float	next_x;
	float	next_y;

	player->rot_angle = normalize_angle(player->rot_angle
			+ player->turn_spd * player->turn_dir);
	next_x = player->x + cos(player->rot_angle)
		* (player->move_dir * player->move_speed);
	next_y = player->y + sin(player->rot_angle)
		* (player->move_dir * player->move_speed);
	if (player->strafe_dir != 0)
	{
		next_x = player->x + cos(player->rot_angle + (0.5 * PI)
				* player->strafe_dir) * (player->move_speed);
		next_y = player->y + sin(player->rot_angle + (0.5 * PI)
				* player->strafe_dir) * (player->move_speed);
	}
	if (!map_is_legal(map, next_x, next_y))
		return ;
	player->x = next_x;
	player->y = next_y;
}

void	update(t_cub3d *c3d)
{
	update_player(c3d->mapdat.map, &c3d->gfx.player);
	cast_rays(&c3d->gfx, &c3d->gfx.player, &c3d->mapdat);
}
