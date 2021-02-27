/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:22:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:23:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/Xlib.h>
#include <math.h>

#include "cub3d_types.h"
#include "mlx.h"
#include "libft/core.h"
#include "libft/io.h"
#include "libft/string.h"
#include "config.h"
#include "cub3d.h"
#include "bmp.h"
#include "events.h"
#include "raycasting.h"
#include "img.h"
#include "misc.h"
#include "gfx.h"
#include "msg.h"

/*
** Ensure the game's resolution is correct, resize it if not.
** If the --save option is specified, no resizing will occur and the
** generated .bmp image will have the specified dimensions.
*/

static void	get_win_res(t_cub3d *c3d)
{
	int	screen_res_y;
	int	screen_res_x;

	c3d->gfx.win_height = c3d->mapdat.win_height;
	c3d->gfx.win_width = c3d->mapdat.win_width;
	if (c3d->opt & OPT_SAVE)
		return ;
	mlx_get_screen_size(c3d->gfx.mlx_ptr, &screen_res_x, &screen_res_y);
	if (c3d->gfx.win_width > (int)screen_res_x)
		c3d->gfx.win_width = screen_res_x;
	if (c3d->gfx.win_height > (int)screen_res_y)
		c3d->gfx.win_height = screen_res_y;
}

bool	init_gfx(t_cub3d *c3d)
{
	c3d->gfx.mlx_ptr = mlx_init();
	if (c3d->gfx.mlx_ptr == NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, MSG_MLX_INIT_FAILED);
		return (false);
	}
	get_win_res(c3d);
	if (!init_raycasting(c3d))
		return (false);
	if (c3d->opt & OPT_SAVE)
		return (render_save_bmp(c3d));
	c3d->gfx.win_ptr = mlx_new_window(c3d->gfx.mlx_ptr, c3d->gfx.win_width,
			c3d->gfx.win_height, c3d->mapdat.map_name);
	if (c3d->gfx.win_ptr == NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, MSG_MLX_WIN_FAILED);
		return (false);
	}
	install_event_handlers(c3d);
	mlx_loop(c3d->gfx.mlx_ptr);
	cub3d_shift_state(c3d, NULL);
	return (true);
}
