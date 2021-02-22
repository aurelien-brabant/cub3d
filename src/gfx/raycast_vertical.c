/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:25:31 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 19:06:20 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>

#include <config.h>

#include "cub3d_misc.h"
#include "cub3d_gfx.h"

/*
** This function only exists to make this code norm compliant.
** Find the xintercept, yintercept, xstep and ystep.
*/

static void	get_data(t_ray *ray, t_player *player,
		double *step, double *intercept)
{
	intercept[0] = floor((player->x / TILE_SIZE)) * TILE_SIZE;
	if (!ray->facing_left)
		intercept[0] += TILE_SIZE;
	intercept[1] = player->y + (intercept[0] - player->x) * tan(ray->angle);
	step[0] = TILE_SIZE;
	if (ray->facing_left)
		step[0] *= -1;
	step[1] = TILE_SIZE * tan(ray->angle);
	if (!ray->facing_down && step[1] > 0)
		step[1] *= -1;
	if (ray->facing_down && step[1] < 0)
		step[1] *= -1;
}

static double	register_hit_distance(t_ray *ray, t_player *player, double *next)
{
	ray->vert_wall_hit[0] = next[0];
	ray->vert_wall_hit[1] = next[1];
	return (get_points_dist(player->x, player->y, ray->vert_wall_hit[0],
			ray->vert_wall_hit[1]));
}

double	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	double	step[2];
	double	intercept[2];
	double	next[2];

	ray->vert_wall_hit[0] = -1;
	ray->vert_wall_hit[1] = -1;
	get_data(ray, player, step, intercept);
	next[0] = intercept[0];
	next[1] = intercept[1];
	if (map_has_wall_at(mapdat->map, player->x, player->y))
		return (register_hit_distance(ray, player, next));
	while (next[0] >= 0 && next[1] >= 0)
	{
		if (map_has_wall_at(mapdat->map, next[0] - ray->facing_left, next[1]))
			return (register_hit_distance(ray, player, next));
		next[0] += step[0];
		next[1] += step[1];
	}
	return (DBL_MAX);
}
