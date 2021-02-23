/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 03:15:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 17:41:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "config.h"
#include "cub3d_types.h"

int	handle_keypress(int keysym, t_cub3d *c3d)
{
	t_player	*player;

	player = &c3d->gfx.player;
	if (keysym == KB_QUIT)
		mlx_loop_end(c3d->gfx.mlx_ptr);
	else if (keysym == KB_TURN_LEFT)
		player->turn_dir = -1;
	else if (keysym == KB_TURN_RIGHT)
		player->turn_dir = 1;
	else if (keysym == KB_MOVE_LEFT)
		player->strafe_dir = -1;
	else if (keysym == KB_MOVE_RIGHT)
		player->strafe_dir = 1;
	else if (keysym == KB_MOVE_FORWARD)
		player->move_dir = 1;
	else if (keysym == KB_MOVE_BACKWARD)
		player->move_dir = -1;
	return (1);
}
