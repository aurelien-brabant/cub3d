/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 19:58:40 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 21:12:02 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "config.h"
#include "cub3d_gfx.h"

static void	raycast(t_vector map, t_ray *ray)
{
	(void)map;
	(void)ray;
}

void	cast_rays(t_vector map, t_graphics *gfx, t_player *player)
{
	size_t	rayId;
	double	rayStep;
	double	rayAngle;
	
	rayId = 0;
	rayStep = (double)(FOV_ANGLE * (M_PI / 180)) / gfx->num_rays;
	rayAngle = player->rot_angle - ((FOV_ANGLE * (M_PI / 180)) / 2);
	while (rayId < gfx->num_rays)
	{
		gfx->rays[rayId].angle = rayAngle;
		raycast(map, &gfx->rays[rayId]);
		rayAngle += rayStep;
		++rayId;
	}
}
