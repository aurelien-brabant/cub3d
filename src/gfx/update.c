/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:45:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 21:13:37 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"

#include "libft/vector.h"

#include "cub3d_gfx.h"
#include "cub3d_misc.h"

static void	update_player(t_vector *map, t_player *player)
{
	unsigned char	mapchar;
	int				nextX;
	int				nextY;

	player->rot_angle += player->turn_spd * player->turn_dir;
	nextX = player->x + cos(player->rot_angle)
		* (player->move_dir * player->move_speed);
	nextY = player->y + sin(player->rot_angle)
		* (player->move_dir * player->move_speed);
	mapchar = map_getchar(map, nextX, nextY);
	if (mapchar != '1' && mapchar != ' ')
	{
		player->x = nextX;
		player->y = nextY;
	}
}

void	update(t_cub3d *c3d)
{
	update_player(c3d->mapdat.map, &c3d->gamedat.player);
	cast_rays(c3d->mapdat.map, &c3d->gfx, &c3d->gamedat.player);
}
