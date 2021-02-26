/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   install_event_handlers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:11:28 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 22:46:19 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <stdio.h>

#include "mlx.h"
#include "events.h"
#include "raycasting.h"

static int	mouse(int button, int x, int y)
{
	(void)button;
	printf("[%d; %d]\n", x, y);
	return (0);
}

void	install_event_handlers(t_cub3d *c3d)
{
	void	*win;

	win = c3d->gfx.win_ptr;
	mlx_hook(win, KeyPress, KeyPressMask, &handle_keypress, c3d);
	mlx_hook(win, KeyRelease, KeyReleaseMask, &handle_keyrelease, c3d);
	mlx_hook(win, ClientMessage, StructureNotifyMask, &mlx_loop_end,
			c3d->gfx.mlx_ptr);
	mlx_mouse_hook(win, &mouse, NULL);
	mlx_loop_hook(c3d->gfx.mlx_ptr, &render, c3d);
}
