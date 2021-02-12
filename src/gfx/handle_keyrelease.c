/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 03:15:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 03:28:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "cub3d_types.h"

int	handle_keyrelease(int keysym, t_cub3d *c3d)
{
	if (keysym == XK_Escape)
		mlx_loop_end(c3d->gfx.mlx_ptr);
	if (keysym == XK_Left || keysym == XK_Right)
		c3d->gamedat.player.turn_dir = 0;
	if (keysym == XK_Up)
		c3d->gamedat.player.move_dir = 0;
	if (keysym == XK_Down)
		c3d->gamedat.player.move_dir = 0;
	return (1);
}
