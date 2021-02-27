/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 01:52:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:37:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>

#include "gfx.h"
#include "misc.h"
#include "raycasting.h"

/* Get xstep and ystep */

static void	get_step(t_ray *ray, t_pos *step)
{
	step->y = TILE_SIZE;
	if (is_ray_facing_top(ray))
		step->y *= -1;
	step->x = TILE_SIZE / tan(ray->angle);
	if (is_ray_facing_left(ray) && step->x > 0)
		step->x *= -1;
	if (is_ray_facing_right(ray) && step->x < 0)
		step->x *= -1;
}

/* Get xintercept and yintercept */

static void	get_intercept(t_ray *ray, t_player *player, t_pos *intercept)
{
	intercept->y = floor((player->pos.y / TILE_SIZE)) * TILE_SIZE;
	if (is_ray_facing_bot(ray))
		intercept->y += TILE_SIZE;
	intercept->x = player->pos.x + (intercept->y - player->pos.y)
		/ tan(ray->angle);
}

/*
** Register the horizontal hit pos in the ray object and return the distance
** from this point and the player.
*/

static double	register_hit_distance(t_ray *ray, t_player *player, t_pos next)
{
	ray->horz_hit.x = next.x;
	ray->horz_hit.y = next.y;
	return (get_points_dist(player->pos.x, player->pos.y, ray->horz_hit.x,
			ray->horz_hit.y));
}

double	get_horz_distance(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	t_pos	step;
	t_pos	intercept;
	t_pos	next;

	get_intercept(ray, player, &intercept);
	get_step(ray, &step);
	next.x = intercept.x;
	next.y = intercept.y;
	if (map_has_wall_at(mapdat->map, player->pos.x, player->pos.y))
		return (register_hit_distance(ray, player, next));
	while (next.x >= 0 && next.y >= 0)
	{
		if (map_has_wall_at(mapdat->map, next.x,
				next.y - is_ray_facing_top(ray)))
			return (register_hit_distance(ray, player, next));
		next.x += step.x;
		next.y += step.y;
	}
	return (DBL_MAX);
}
