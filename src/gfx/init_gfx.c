/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:22:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 14:15:31 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <math.h>

#include "cub3d_types.h"
#include "mlx.h"

#include "config.h"

#include "libft/core.h"
#include "libft/io.h"
#include "libft/string.h"

#include "cub3d_misc.h"
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

static void	init_player(t_vector map, t_player *player)
{
	unsigned char	spawn_char;
	
	player->turn_dir = 0;
	player->turn_spd = 3 * (M_PI / 180);
	player->move_speed = 3;
	player->move_dir = 0;
	player->x = player->x * TILE_SIZE + (TILE_SIZE / 2.0);
	player->y = player->y * TILE_SIZE + (TILE_SIZE / 2.0);
	spawn_char = map_getchar(map, player->x, player->y);
	if (spawn_char == 'E')
		player->rot_angle = 0 * (M_PI / 180);
	if (spawn_char == 'W')
		player->rot_angle = 180 * (M_PI / 180);
	if (spawn_char == 'N')
		player->rot_angle = 270 * (M_PI / 180);
	if (spawn_char == 'S')
		player->rot_angle = 90 * (M_PI / 180);
}

static void	init_raycasting(t_graphics *gfx, t_map_data *mapdat, char *err)
{
	gfx->num_rays = mapdat->win_width;
	gfx->rays = ft_calloc(gfx->num_rays, sizeof(*gfx->rays));
	if (gfx->rays == NULL)
		ft_snprintf(err, ERR_LEN, "Failed to initialize rays.");
}

int	init_gfx(t_cub3d *c3d)
{
	c3d->gfx.mlx_ptr = mlx_init();
	if (c3d->gfx.mlx_ptr == NULL)
		ft_snprintf(c3d->err, ERR_LEN, "Failed to initialize minilibx.");
	if (c3d->err[0] != '\0')
		return (0);
	normalize_res(c3d->gfx.mlx_ptr, &c3d->mapdat.win_width,
			&c3d->mapdat.win_height);
	init_player(c3d->mapdat.map, &c3d->gamedat.player);
	init_raycasting(&c3d->gfx, &c3d->mapdat, c3d->err);
	c3d->gfx.win_ptr = mlx_new_window(c3d->gfx.mlx_ptr, c3d->mapdat.win_width,
			c3d->mapdat.win_height, "cub3D");
	if (c3d->gfx.win_ptr == NULL || !init_dpimg(&c3d->gfx,
				c3d->mapdat.win_width, c3d->mapdat.win_height))
		ft_snprintf(c3d->err, ERR_LEN, "Gfx init failed.");
	if (c3d->err[0] != '\0')
		return (0);
	mlx_hook(c3d->gfx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, c3d);
	mlx_hook(c3d->gfx.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, c3d);
	mlx_mouse_hook(c3d->gfx.win_ptr, handle_mouse, c3d);
	mlx_loop_hook(c3d->gfx.mlx_ptr, &render, c3d);
	mlx_loop(c3d->gfx.mlx_ptr);
	cub3d_shift_state(c3d, NULL);
	return (1);
}
