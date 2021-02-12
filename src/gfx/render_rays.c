/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 20:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 20:43:39 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d_gfx.h"

void	render_rays(t_player *player, t_graphics *gfx)
{
	size_t	rayId;
	t_ray	*ray;

	rayId = 0;
	while (rayId < gfx->num_rays)
	{
		ray = &gfx->rays[rayId];
		draw_line(&gfx->dpimg[1], (t_line){player->x, player->y, player->x + cos(ray->angle) * 30, player->y + sin(ray->angle) * 30}, 0xFF0000);
		++rayId;
	}
}
