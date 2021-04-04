/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:20:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/04/04 09:01:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_types.h"
#include "gfx.h"
#include "raycasting.h"
#include "misc.h"
#include "msg.h"
#include "img.h"
#include "config.h"
#include "libft/core.h"
#include "libft/io.h"

static double	get_initial_player_rot_angle(unsigned char spawn_char)
{
	if (spawn_char == 'E')
		return (0);
	if (spawn_char == 'W')
		return (M_PI);
	if (spawn_char == 'N')
		return (M_PI * 1.5);
	if (spawn_char == 'S')
		return (M_PI_2);
	c3d_warn("No suitable spawn location found at ST_RUNNING time."
		"This should have been handled by parsing!");
	return (0);
}

static void	init_player(t_vector map, t_player *player)
{
	unsigned char	spawn_char;

	player->turn_dir = 0;
	player->turn_spd = deg2rad(3);
	player->move_speed = 6;
	player->move_dir = 0;
	player->pos.x = player->pos.x * TILE_SIZE + (TILE_SIZE / 2.0);
	player->pos.y = player->pos.y * TILE_SIZE + (TILE_SIZE / 2.0);
	spawn_char = map_getchar(map, player->pos.x, player->pos.y);
	player->rot_angle = get_initial_player_rot_angle(spawn_char);
}

/*
** NOTE: how the distance to the projection plane is calculated:
** Simple trigonometry formula application. The formula used here
** is: adjacent = opposite / tan.
** The length of the adjacent side is basically the distance to the projection
** plane that we'll extensively use when drawing the walls on the screen.
*/

bool	init_raycasting(t_cub3d *c3d)
{
	int		ray_id;

	ray_id = 0;
	init_player(c3d->mapdat.map, &c3d->gfx.player);
	if (!init_sprites(c3d) || !init_img(c3d))
		return (false);
	c3d->gfx.num_rays = c3d->gfx.win_width;
	c3d->gfx.fov = deg2rad(FOV_ANGLE);
	c3d->gfx.dist_proj_plane = (c3d->gfx.win_width / 2.0)
		/ tan(c3d->gfx.fov / 2);
	c3d->gfx.rays = ft_calloc(c3d->gfx.num_rays, sizeof(t_ray));
	if (c3d->gfx.rays == NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, MSG_RAY_BADALLOC);
		return (false);
	}
	while (ray_id < c3d->gfx.num_rays)
	{
		c3d->gfx.rays[ray_id].id = ray_id;
		++ray_id;
	}
	return (true);
}
