/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:25:31 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/25 02:03:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>

#include "raycasting.h"
#include "misc.h"
#include "gfx.h"

/*
** This function only exists to make this code norm compliant.
** Find the xintercept, yintercept, xstep and ystep.
*/

#include <stdio.h>

static void	get_data(t_ray *ray, t_player *player,
		float *step, float *intercept)
{
	intercept[0] = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray))
		intercept[0] += TILE_SIZE;
	intercept[1] = player->y + (intercept[0] - player->x) * tan(ray->angle);
	step[0] = TILE_SIZE;
	if (is_ray_facing_left(ray))
		step[0] *= -1;
	step[1] = TILE_SIZE * tan(ray->angle);
	if (ray->id == 360)
	{
		//printf("STEP X: %f\nSTEP Y: %f\n", step[0], step[1]);
		printf("INTERCEPT X: %.7f\nINTERCEPT Y: %.7f\n", intercept[0], intercept[1]);
	}
	if (is_ray_facing_top(ray) && step[1] > 0)
		step[1] *= -1;
	if (is_ray_facing_bot(ray) && step[1] < 0)
		step[1] *= -1;
}

static float	register_hit_distance(t_ray *ray, t_player *player,
		float *next)
{
	ray->vert_wall_hit[0] = next[0];
	ray->vert_wall_hit[1] = next[1];
	return (get_points_dist(player->x, player->y, ray->vert_wall_hit[0],
			ray->vert_wall_hit[1]));
}

float	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	float	step[2];
	float	intercept[2];
	float	next[2];

	ray->vert_wall_hit[0] = -1;
	ray->vert_wall_hit[1] = -1;
	get_data(ray, player, step, intercept);
	next[0] = intercept[0];
	next[1] = intercept[1];
	if (map_has_wall_at(mapdat->map, player->x, player->y))
		return (register_hit_distance(ray, player, next));
	while (next[0] >= 0 && next[1] >= 0)
	{
		if (map_has_wall_at(mapdat->map, next[0]
					- is_ray_facing_left(ray), next[1]))
				return (register_hit_distance(ray, player, next));
		next[0] += step[0];
		next[1] += step[1];
	}
	return (DBL_MAX);
}
