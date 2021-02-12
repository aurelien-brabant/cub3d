/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:12:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 03:29:34 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "config.h"
#include "cub3d_gfx.h"
#include <math.h>

void	render_player(t_img *img, t_player *player)
{
	int x;
	int y;

	x = round(player->x * MINIMAP_FACTOR);
	y = round(player->y * MINIMAP_FACTOR);
	draw_rect(img, (t_rect){x, y, 10, 10, 0, 0xFF0000}, 0xFF00);
	//draw_line(img, (t_line){x, y, x + cos(player->rot_angle) * 30, y + sin(player->rot_angle) * 30}, 0xFF);
	img_pix_put(img, x + cos(player->rot_angle) * 30, y + sin(player->rot_angle) * 30, 0xFF);
}
