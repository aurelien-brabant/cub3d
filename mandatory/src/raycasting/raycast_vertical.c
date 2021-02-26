/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:25:31 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:11:21 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>

#include "raycasting.h"
#include "misc.h"
#include "gfx.h"

/* Get the xintercept and the yintercept */

static void	get_intercept(t_ray *ray, t_player *player, t_pos *intercept)
{
	intercept->x = floor(player->pos.x / TILE_SIZE) * TILE_SIZE;
	if (is_ray_facing_right(ray))
		intercept->x += TILE_SIZE;
	intercept->y = player->pos.y + (intercept->x - player->pos.x)
		* tan(ray->angle);
}

/* Get xstep and ystep */

static void	get_step(t_ray *ray, t_pos *step)
{
	step->x = TILE_SIZE;
	if (is_ray_facing_left(ray))
		step->x *= -1;
	step->y = TILE_SIZE * tan(ray->angle);
	if (is_ray_facing_top(ray) && step->y > 0)
		step->y *= -1;
	if (is_ray_facing_bot(ray) && step->y < 0)
		step->y *= -1;
}

static double	register_hit_distance(t_ray *ray, t_player *player, t_pos next)
{
	ray->vert_hit.x = next.x;
	ray->vert_hit.y = next.y;
	return (get_points_dist(player->pos.x, player->pos.y, ray->vert_hit.x,
			ray->vert_hit.y));
}

double	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat)
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
		if (map_has_wall_at(mapdat->map, next.x
				- is_ray_facing_left(ray), next.y))
			return (register_hit_distance(ray, player, next));
		next.x += step.x;
		next.y += step.y;
	}
	return (DBL_MAX);
}
