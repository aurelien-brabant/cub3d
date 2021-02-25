/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:58:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/25 03:17:20 by abrabant         ###   ########.fr       */
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
** cast an individual ray
*/

static void	raycast(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	float	horz_dist;
	float	vert_dist;

	ray->angle = normalize_angle(ray->angle);
	horz_dist = get_horz_distance(ray, player, mapdat);
	vert_dist = get_vert_distance(ray, player, mapdat);
	ray->hit_vert = vert_dist <= horz_dist;
	if (ray->id == 360)
	{
		printf("VERT: (%.6f; %.6f)\n", ray->vert_wall_hit[0], ray->vert_wall_hit[1]);
		printf("HORZ: (%.6f; %.6f)\n", ray->horz_wall_hit[0], ray->horz_wall_hit[1]);
		printf("%d\n", ray->hit_vert);
	}
	if (ray->hit_vert)
	{
		ray->wall_hit[0] = ray->vert_wall_hit[0];
		ray->wall_hit[1] = ray->vert_wall_hit[1];
		ray->wall_dist = vert_dist;
	}
	else
	{
		ray->wall_hit[0] = ray->horz_wall_hit[0];
		ray->wall_hit[1] = ray->horz_wall_hit[1];
		ray->wall_dist = horz_dist;
	}
	if (ray->wall_dist == 0)
		ray->wall_dist = 1;
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
	int				ray_id;
	float			ray_angle;

	ray_id = 0;
	ray_angle = player->rot_angle - (gfx->fov / 2.0);
	while (ray_id < gfx->num_rays)
	{
		gfx->rays[ray_id].angle = player->rot_angle
			+ atan((ray_id - gfx->num_rays / 2.0) / gfx->dist_proj_plane);
		gfx->rays[ray_id].angle = ray_angle;
		ray_angle += (gfx->fov / gfx->num_rays);
		raycast(&gfx->rays[ray_id], player, mapdat);
		++ray_id;
	}
}
