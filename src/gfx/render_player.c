/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:12:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 18:32:16 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "config.h"
#include "cub3d_gfx.h"

void	render_player(t_img *img, t_player *player)
{
	int x;
	int y;

	x = floor(player->x * MINIMAP_FACTOR);
	y = floor(player->y * MINIMAP_FACTOR);
	draw_circle(img, x, y, MINIMAP_FACTOR * 10);
	draw_line(img, (t_line){x, y, x + cos(player->rot_angle) * 30, y + sin(player->rot_angle) * 30}, 0xFF);
}
