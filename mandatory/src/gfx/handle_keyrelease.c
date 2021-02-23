/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 03:15:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/21 15:49:12 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "config.h"
#include "cub3d_types.h"

int	handle_keyrelease(int keysym, t_cub3d *c3d)
{
	t_player	*player;

	player = &c3d->gfx.player;
	if (keysym == KB_TURN_LEFT || keysym == KB_TURN_RIGHT)
		player->turn_dir = 0;
	if (keysym == KB_MOVE_FORWARD || keysym == KB_MOVE_BACKWARD)
		player->move_dir = 0;
	if (keysym == KB_MOVE_LEFT || keysym == KB_MOVE_RIGHT)
		player->strafe_dir = 0;
	return (1);
}
