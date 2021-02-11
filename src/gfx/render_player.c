/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 21:12:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 22:59:42 by abrabant         ###   ########.fr       */
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
	draw_rect(img, (t_rect){x, y, 4, 4, 0, 0xFF0000}, 0xFF00);
}
