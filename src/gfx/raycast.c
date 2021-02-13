/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:58:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 02:50:31 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "cub3d_misc.h"

#include "config.h"
#include "cub3d_gfx.h"

#include "cub3d_types.h"
#include "libft/string.h"

static double	normalize_angle(double angle)
{
	if (angle > M_PI * 2)
		angle = fmod(angle, M_PI * 2);
	if (angle < 0)
		angle = M_PI * 2 - fmod(-angle, M_PI * 2);
	return (angle);
}

static void	raycast(t_ray *ray, t_player *player, t_map_data *mapdat)
{
	ray->angle = normalize_angle(ray->angle);
	if (ray->angle > M_PI / 2 && ray->angle < M_PI * 1.5)
		ray->facing_left = 1;
	if (ray->angle > 0 && ray->angle < M_PI)
		ray->facing_down = 1;
	get_horz_distance(ray, player, mapdat);
	get_vert_distance(ray, player, mapdat);
}

void	cast_rays(t_graphics *gfx, t_player *player, t_map_data *mapdat)
{
	size_t	rayId;
	double	rayStep;
	double	rayAngle;
	
	rayId = 0;
	rayStep = (double)(FOV_ANGLE * (M_PI / 180)) / gfx->num_rays;
	rayAngle = player->rot_angle - ((FOV_ANGLE * (M_PI / 180)) / 2);
	//while (rayId < gfx->num_rays)
	while (rayId < 1)
	{
		ft_memset(&gfx->rays[rayId], 0, sizeof (t_ray));
		gfx->rays[rayId].angle = rayAngle;
		raycast(&gfx->rays[rayId], player, mapdat);
		rayAngle += rayStep;
		++rayId;
	}
}
