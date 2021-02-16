/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:58:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/16 17:06:08 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_gfx.h"
#include "cub3d_misc.h"
#include "cub3d_types.h"
#include "config.h"

#include "libft/string.h"

/*
** Ensure the angle is between 0 and 2 PI radians.
*/

static double	normalize_angle(double angle)
{
	if (angle > M_PI * 2)
		angle = fmod(angle, M_PI * 2);
	if (angle < 0)
		angle = M_PI * 2 - fmod(-angle, M_PI * 2);
	return (angle);
}

/*
** cast an individual ray
*/

static void	raycast(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	double	horz_dist;
	double	vert_dist;

	ray->angle = normalize_angle(ray->angle);
	ray->facing_left = ray->angle > M_PI / 2 && ray->angle < M_PI * 1.5;
	ray->facing_down = ray->angle > 0 && ray->angle < M_PI;
	horz_dist = get_horz_distance(ray, player, mapdat);
	vert_dist = get_vert_distance(ray, player, mapdat);
	ray->hit_vert = horz_dist >= vert_dist;
	if (ray->vert_wall_hit[0] != -1 && horz_dist >= vert_dist)
	{
		ray->wall_hit[0] = ray->vert_wall_hit[0];
		ray->wall_hit[1] = ray->vert_wall_hit[1];
		ray->wall_dist = vert_dist + (vert_dist == 0);
	}
	else if (ray->horz_wall_hit[0] != -1 && vert_dist > horz_dist)
	{
		ray->wall_hit[0] = ray->horz_wall_hit[0];
		ray->wall_hit[1] = ray->horz_wall_hit[1];
		ray->wall_dist = horz_dist + (horz_dist == 0); 
	}
	else
		c3d_warn("No intersection found. This is a BUG!");
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
	double	ray_angle;

	ray_id = 0;
	ray_angle = player->rot_angle - (gfx->fov / 2);
	while (ray_id < gfx->num_rays)
	{
		gfx->rays[ray_id].angle = player->rot_angle
			+ atan((ray_id - gfx->num_rays / 2.0) / gfx->dist_proj_plane);
		raycast(&gfx->rays[ray_id], player, mapdat);
		++ray_id;
	}
}
