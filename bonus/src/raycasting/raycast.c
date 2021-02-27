/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:58:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 23:53:54 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "gfx.h"
#include "misc.h"
#include "raycasting.h"
#include "config.h"
#include "libft/string.h"

/*
** Cast an individual ray.
**
** The ray distance can't be set to zero as it used as a divisor to compute
** the projected wall_height. For that reason, a ray->dist of zero is
** automatically changed to 1.
*/

static void	raycast(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	double	horz_dist;
	double	vert_dist;

	ray->angle = normalize_angle(ray->angle);
	horz_dist = get_horz_distance(ray, player, mapdat);
	vert_dist = get_vert_distance(ray, player, mapdat);
	ray->was_hit_vert = vert_dist < horz_dist;
	if (ray->was_hit_vert)
	{
		ray->hit.x = ray->vert_hit.x;
		ray->hit.y = ray->vert_hit.y;
		ray->dist = vert_dist;
	}
	else
	{
		ray->hit.x = ray->horz_hit.x;
		ray->hit.y = ray->horz_hit.y;
		ray->dist = horz_dist;
	}
	if (ray->dist == 0)
		ray->dist = 1;
}

/*
** The ray angle is determined for each ray individually in order
** to keep the same distance between each ray. It prevents distortion
** to occur, especially at the extremes of the field of view.
**
** atan(pixel_offset / distance to proj. plane) gives the correct angle.
*/

void	cast_rays(t_graphics *gfx, t_player *player, t_map_data *mapdat)
{
	int		ray_id;

	ray_id = 0;
	while (ray_id < gfx->num_rays)
	{
		gfx->rays[ray_id].angle = player->rot_angle
			+ atan((ray_id - gfx->num_rays / 2.0) / gfx->dist_proj_plane);
		raycast(&gfx->rays[ray_id], player, mapdat);
		++ray_id;
	}
}
