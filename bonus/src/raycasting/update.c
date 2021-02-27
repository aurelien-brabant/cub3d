/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 02:45:10 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 19:19:38 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <time.h>

#include "config.h"
#include "cub3d_types.h"
#include "gfx.h"
#include "misc.h"
#include "raycasting.h"
#include "libft/vector.h"

#include <stdio.h>

static void	wait_for_next_frame(t_graphics *gfx)
{
	static int8_t	fps = 0;
	struct timespec	diff_timespec;
	int64_t			diff;
	int64_t			ticks;

	ticks = c3d_get_ticks(gfx);
	if (ticks > gfx->last_sec_ticks + 1000)
	{
		gfx->last_sec_ticks = ticks;
		gfx->fps = fps;
		fps = 0;
	}
	diff = (gfx->last_frame_ticks + gfx->frame_time) - c3d_get_ticks(gfx);
	if (diff > 0)
	{
		diff_timespec.tv_sec = diff / 1000;
		diff_timespec.tv_nsec = (diff % 1000) * 1000000;
		nanosleep(&diff_timespec, &diff_timespec);
	}
	ticks = c3d_get_ticks(gfx);
	gfx->delta_time = (ticks - gfx->last_frame_ticks) / 1000.0;
	gfx->last_frame_ticks = ticks;
	++fps;
}

static void	update_player(t_vector *map, t_player *player, double dtime)
{
	double	next_x;
	double	next_y;
	double	turnspd;
	double	movespd;

	movespd = player->move_speed * dtime;
	turnspd = player->turn_spd * dtime;
	player->rot_angle = normalize_angle(player->rot_angle
			+ (player->turn_dir * turnspd));
	next_x = player->pos.x + cos(player->rot_angle)
		* (player->move_dir * movespd);
	next_y = player->pos.y + sin(player->rot_angle)
		* (player->move_dir * movespd);
	if (player->strafe_dir != 0)
	{
		next_x = player->pos.x + cos(player->rot_angle + (0.5 * M_PI)
				* player->strafe_dir) * movespd;
		next_y = player->pos.y + sin(player->rot_angle + (0.5 * M_PI)
				* player->strafe_dir) * movespd;
	}
	if (map_has_wall_at(map, next_x, next_y))
		return ;
	player->pos.x = next_x;
	player->pos.y = next_y;
}

void	update(t_cub3d *c3d)
{
	update_player(c3d->mapdat.map, &c3d->gfx.player, c3d->gfx.delta_time);
	cast_rays(&c3d->gfx, &c3d->gfx.player, &c3d->mapdat);
	wait_for_next_frame(&c3d->gfx);
}
