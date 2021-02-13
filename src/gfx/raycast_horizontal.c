/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 01:52:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 16:33:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>

#include <config.h>

#include "cub3d_gfx.h"
#include "cub3d_misc.h"

/*
** This function only exists to make this code norm compliant
*/

static void	get_data(t_ray *ray, t_player *player, double *step, double *intercept)
{
	intercept[1] = floor((player->y / TILE_SIZE)) * TILE_SIZE;
	if (ray->facing_down)
		intercept[1] += TILE_SIZE;
	intercept[0] = player->x + (intercept[1] - player->y) / tan(ray->angle);
	step[1] = TILE_SIZE;
	if (!ray->facing_down)
		step[1] *= -1;
	step[0] = TILE_SIZE / tan(ray->angle);
	if (ray->facing_left && step[0] > 0)
		step[0] *= -1;
	if (!ray->facing_left && step[0] < 0)
		step[0] *= -1;
}

double	get_horz_distance(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	double	step[2];
	double	intercept[2];
	double	next[2];

	ray->horz_wall_hit[0] = -1;
	ray->horz_wall_hit[1] = -1;
	get_data(ray, player, step, intercept);
	next[0] = intercept[0];
	next[1] = intercept[1];
	while (next[0] >= 0 && next[0] < mapdat->win_width && next[1] >= 0 && next[1] < mapdat->win_height)
	{
		if (map_has_wall_at(mapdat->map, next[0], next[1] - !ray->facing_down))
		{
			ray->horz_wall_hit[0] = next[0];
			ray->horz_wall_hit[1] = next[1];
			return (get_points_dist(player->x, player->y, ray->horz_wall_hit[0],
					ray->horz_wall_hit[1]));
		}
		next[0] += step[0];
		next[1] += step[1];
	}
	return (DBL_MAX);
}
