/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:45:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 14:00:56 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d_types.h"
#include "cub3d_misc.h"

#include "config.h"

#include "libft/vector.h"

static void	update_player(t_vector *map, t_player *player)
{
	int	nextX;
	int nextY;

	player->rot_angle += player->turn_spd * player->turn_dir;
	nextX = player->x + cos(player->rot_angle)
		* (player->move_dir * player->move_speed);
	nextY = player->y + sin(player->rot_angle)
		* (player->move_dir * player->move_speed);
	if (map_getchar(map, nextX, nextY) != '1')
	{
		player->x = nextX;
		player->y = nextY;
	}
}

void	update(t_cub3d *c3d)
{
	update_player(c3d->mapdat.map, &c3d->gamedat.player);
}
