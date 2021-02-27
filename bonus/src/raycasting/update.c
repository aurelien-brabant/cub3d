/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:45:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 02:26:37 by abrabant         ###   ########.fr       */
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
	double	next_x;
	double	next_y;

	player->rot_angle = normalize_angle(player->rot_angle
			+ player->turn_spd * player->turn_dir);
	next_x = player->pos.x + cos(player->rot_angle)
		* (player->move_dir * player->move_speed);
	next_y = player->pos.y + sin(player->rot_angle)
		* (player->move_dir * player->move_speed);
	if (player->strafe_dir != 0)
	{
		next_x = player->pos.x + cos(player->rot_angle + (0.5 * M_PI)
				* player->strafe_dir) * (player->move_speed);
		next_y = player->pos.y + sin(player->rot_angle + (0.5 * M_PI)
				* player->strafe_dir) * (player->move_speed);
	}
	if (map_has_wall_at(map, next_x, next_y))
		return ;
	player->pos.x = next_x;
	player->pos.y = next_y;
}

void	update(t_cub3d *c3d)
{
	update_player(c3d->mapdat.map, &c3d->gfx.player);
	cast_rays(&c3d->gfx, &c3d->gfx.player, &c3d->mapdat);
}
