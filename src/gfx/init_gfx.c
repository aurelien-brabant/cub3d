/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:22:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 03:24:47 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <math.h>

#include <stdio.h>

#include "config.h"
#include "mlx.h"
#include "libft/io.h"
#include "cub3d_gfx.h"
#include "cub3d_core.h"

static void	normalize_res(void *mlx_ptr, long long *width, long long *height)
{
	int	dpy_height;
	int	dpy_width;

	mlx_get_screen_size(mlx_ptr, &dpy_width, &dpy_height);
	if (*width > dpy_width)
		*width = dpy_width;
	if (*height > dpy_height)
		*height = dpy_height;
}

static int	init_dpimg(t_graphics *gfx, long long width, long long height)
{
	gfx->dpimg[0].mlx_img = mlx_new_image(gfx->mlx_ptr, width, height);
	gfx->dpimg[1].mlx_img = mlx_new_image(gfx->mlx_ptr, width, height);
	gfx->dpimg[0].width = width;
	gfx->dpimg[1].width = width;
	gfx->dpimg[0].height = height;
	gfx->dpimg[1].height = height;
	if (gfx->dpimg[0].mlx_img == NULL || gfx->dpimg[1].mlx_img == NULL)
		return (0);
	gfx->dpimg[0].addr = mlx_get_data_addr(gfx->dpimg[0].mlx_img, 
			&gfx->dpimg[0].bpp, &gfx->dpimg[0].line_len, &gfx->dpimg[0].endian);
	gfx->dpimg[1].addr = mlx_get_data_addr(gfx->dpimg[1].mlx_img, 
			&gfx->dpimg[1].bpp, &gfx->dpimg[1].line_len, &gfx->dpimg[1].endian);
	return (1);
}

/*
** Transform the map coordinates to those of the window.
** Position the player in the middle of its spawnpoint.
*/

static void	normalize_player_coords(t_player *player)
{
	player->rot_angle = 0 * (M_PI / 180);  
	player->turn_dir = 0;
	player->turn_spd = 5 * (M_PI / 180);
	player->move_speed = 5;
	player->move_dir = 0;
	player->x = player->x * TILE_SIZE + (TILE_SIZE / 2.0);
	player->y = player->y * TILE_SIZE + (TILE_SIZE / 2.0);
}

int	init_gfx(t_cub3d *c3d)
{
	c3d->gfx.mlx_ptr = mlx_init();
	if (c3d->gfx.mlx_ptr == NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, "Failed to initialize minilibx.");
		return (0);
	}
	normalize_res(c3d->gfx.mlx_ptr, &c3d->mapdat.win_width,
			&c3d->mapdat.win_height);
	normalize_player_coords(&c3d->gamedat.player);
	c3d->gfx.win_ptr = mlx_new_window(c3d->gfx.mlx_ptr, c3d->mapdat.win_width,
			c3d->mapdat.win_height, "cub3D");
	if (c3d->gfx.win_ptr == NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, "Failed to create game window.");
		return (0);
	}
	if (!init_dpimg(&c3d->gfx, c3d->mapdat.win_width, c3d->mapdat.win_height))
	{
		ft_snprintf(c3d->err, ERR_LEN, "Failed to initialize display images.");
		return (0);
	}
	mlx_hook(c3d->gfx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, c3d);
	mlx_hook(c3d->gfx.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, c3d);
	mlx_mouse_hook(c3d->gfx.win_ptr, handle_mouse, c3d);
	mlx_loop_hook(c3d->gfx.mlx_ptr, &render, c3d);
	mlx_loop(c3d->gfx.mlx_ptr);
	cub3d_shift_state(c3d, NULL);
	return (1);
}
