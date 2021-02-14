/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 03:15:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 23:48:28 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "cub3d_types.h"

int	handle_keypress(int keysym, t_cub3d *c3d)
{
	if (keysym == XK_Escape)
		mlx_loop_end(c3d->gfx.mlx_ptr);
	if (keysym == XK_Left)
		c3d->gamedat.player.turn_dir = -1;
	if (keysym == XK_Right)
		c3d->gamedat.player.turn_dir = 1;
	if (keysym == XK_Up)
		c3d->gamedat.player.move_dir = 1;
	if (keysym == XK_Down)
		c3d->gamedat.player.move_dir = -1;
	return (1);
}
