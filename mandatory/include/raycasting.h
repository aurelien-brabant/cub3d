/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:27:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:20:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "cub3d_types.h"
# define TILE_SIZE 64

/* INIT */

bool	init_raycasting(t_cub3d *c3d);
bool	init_sprites(t_cub3d *c3d);

/* DRAW */

int		draw_sprite(t_sprite *sprite, size_t i, t_cub3d *c3d);
void	draw_sprite_projection(t_cub3d *c3d);
void	draw_walls(t_graphics *gfx, int *colors);
void	draw_aim(t_graphics *gfx);
int		render(t_cub3d *c3d);

/* COMPUTE */

void	update(t_cub3d *c3d);
void	cast_rays(t_graphics *gfx, t_player *player, t_map_data *mapdat);
double	get_horz_distance(t_ray *ray, t_player *player, t_map_data *mapdat);
double	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat);

/* UTILS */

bool	is_ray_facing_left(t_ray *ray);
bool	is_ray_facing_right(t_ray *ray);
bool	is_ray_facing_top(t_ray *ray);
bool	is_ray_facing_bot(t_ray *ray);

#endif /* RAYCASTING_H */
