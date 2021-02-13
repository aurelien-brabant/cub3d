/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 02:25:31 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 03:17:41 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include <config.h>

#include "cub3d_misc.h"
#include "cub3d_types.h"

/*
** This function only exists to make this code norm compliant
*/

static void	get_data(t_ray *ray, t_player *player, double *step, double *intercept)
{
	intercept[0] = floor((player->x / TILE_SIZE)) * TILE_SIZE;
	if (!ray->facing_left)
		intercept[0] += TILE_SIZE;
	intercept[1] = player->y - (player->x - intercept[0]) * tan(ray->angle);
	step[0] = TILE_SIZE;
	if (ray->facing_left)
		step[0] *= -1;
	step[1] = (intercept[0] - step[0]) * tan(ray->angle);
	if (!ray->facing_down && step[1] > 0)
		step[1] *= -1;
	if (ray->facing_down && step[1] < 0)
		step[1] *= -1;
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
	while (next[0] >= 0 && next[0] < mapdat->win_width && next[1] >= 0 && next[1] < 11 * TILE_SIZE)
	{
		if (map_has_wall_at(mapdat->map, next[0] - !ray->facing_left, next[1]))
		{
			ray->vert_wall_hit[0] = next[0];
			ray->vert_wall_hit[1] = next[1];
			break ;
		}
		next[0] += step[0];
		next[1] += step[1];
	}
	return (0);
}
