/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:45:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 03:22:42 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_types.h>
#include <math.h>

static void	update_player(t_player *player)
{
	player->rot_angle += player->turn_spd * player->turn_dir;
	
	player->x += cos(player->rot_angle) * (player->move_dir * player->move_speed);
	player->y += sin(player->rot_angle) * (player->move_dir * player->move_speed);
}

void	update(t_cub3d *c3d)
{
	update_player(&c3d->gamedat.player);
}
