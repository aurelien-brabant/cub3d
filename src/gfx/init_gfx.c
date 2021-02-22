/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 02:22:34 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 18:31:58 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/X.h>
#include <X11/Xlib.h>
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

static void	init_player(t_vector map, t_player *player)
{
	unsigned char	spawn_char;

	player->turn_dir = 0;
	player->turn_spd = deg2rad(3);
	player->move_speed = 3;
	player->move_dir = 0;
	player->x = player->x * TILE_SIZE + (TILE_SIZE / 2.0);
	player->y = player->y * TILE_SIZE + (TILE_SIZE / 2.0);
	spawn_char = map_getchar(map, player->x, player->y);
	if (spawn_char == 'E')
		player->rot_angle = 0;
	if (spawn_char == 'W')
		player->rot_angle = M_PI;
	if (spawn_char == 'N')
		player->rot_angle = M_PI * 1.5;
	if (spawn_char == 'S')
		player->rot_angle = M_PI * 0.5;
}

static int	init_raycasting(t_graphics *gfx, t_map_data *mapdat, char *err)
{
	int		ray_id;
	size_t	alloc_size;

	(void)mapdat;
	gfx->num_rays = gfx->win_width;
	gfx->fov = deg2rad(FOV_ANGLE);
	gfx->dist_proj_plane = (gfx->win_width / 2.0) / tan(gfx->fov / 2);
	alloc_size = gfx->num_rays * sizeof (*gfx->rays);
	gfx->rays = ft_calloc(gfx->num_rays, sizeof(*gfx->rays));
	if (gfx->rays == NULL)
		return (!ft_snprintf(err, ERR_LEN, 
				"Failed to init rays (tried to alloc %ld KB)",
				alloc_size / 1000));
	ray_id = 0;
	while (ray_id < gfx->num_rays)
	{
		gfx->rays[ray_id].id = ray_id;
		++ray_id;
	}
	return (1);
}

static void	hook_and_loop(t_cub3d *c3d)
{
	mlx_hook(c3d->gfx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, c3d);
	mlx_hook(c3d->gfx.win_ptr, KeyRelease, KeyReleaseMask,
			&handle_keyrelease, c3d);
	mlx_hook(c3d->gfx.win_ptr, ClientMessage, StructureNotifyMask,
			&mlx_loop_end, c3d->gfx.mlx_ptr);
	mlx_mouse_hook(c3d->gfx.win_ptr, handle_mouse, c3d);
	mlx_loop_hook(c3d->gfx.mlx_ptr, &render, c3d);
	mlx_loop(c3d->gfx.mlx_ptr);
}

int	init_gfx(t_cub3d *c3d)
{
	c3d->gfx.mlx_ptr = mlx_init();
	if (c3d->gfx.mlx_ptr == NULL)
		return (!ft_snprintf(c3d->err, ERR_LEN, "Failed to init mlx."));
	get_win_res(c3d);
	init_player(c3d->mapdat.map, &c3d->gfx.player);
	if (!init_raycasting(&c3d->gfx, &c3d->mapdat, c3d->err))
		return (0);
	if (!init_img(c3d, &c3d->mapdat) || c3d->err[0] != '\0')
		return (0);
	if (c3d->opt & OPT_SAVE)
		return (render_save_bmp(c3d));
	c3d->gfx.win_ptr = mlx_new_window(c3d->gfx.mlx_ptr, c3d->gfx.win_width,
			c3d->gfx.win_height, c3d->mapdat.map_name);
	if (c3d->gfx.win_ptr == NULL)
		return (!ft_snprintf(c3d->err, ERR_LEN, "Failed to init mlx win."));
	hook_and_loop(c3d);
	cub3d_shift_state(c3d, NULL);
	return (1);
}
