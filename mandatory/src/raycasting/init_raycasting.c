/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:20:36 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/24 15:36:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "gfx.h"
#include "raycasting.h"
#include "misc.h"
#include "msg.h"
#include "img.h"
#include "config.h"
#include "libft/core.h"
#include "libft/io.h"

static void	init_player(t_vector map, t_player *player)
{
	unsigned char	spawn_char;

	player->turn_dir = 0;
	player->turn_spd = deg2rad(3);
	player->move_speed = 6;
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

uint8_t	init_raycasting(t_cub3d *c3d)
{
	int		ray_id;
	size_t	alloc_size;

	init_player(c3d->mapdat.map, &c3d->gfx.player);
	if (!init_sprites(c3d) || !init_img(c3d))
		return (0);
	c3d->gfx.num_rays = c3d->gfx.win_width;
	c3d->gfx.fov = deg2rad(FOV_ANGLE);
	c3d->gfx.dist_proj_plane = (c3d->gfx.win_width / 2.0)
		/ tan(c3d->gfx.fov / 2);
	alloc_size = c3d->gfx.num_rays * sizeof (*c3d->gfx.rays);
	c3d->gfx.rays = ft_calloc(c3d->gfx.num_rays, sizeof(*c3d->gfx.rays));
	if (c3d->gfx.rays == NULL)
		return (!ft_snprintf(c3d->err, ERR_LEN, MSG_RAY_BADALLOC));
	ray_id = 0;
	while (ray_id < c3d->gfx.num_rays)
	{
		c3d->gfx.rays[ray_id].id = ray_id;
		++ray_id;
	}
	return (1);
}
