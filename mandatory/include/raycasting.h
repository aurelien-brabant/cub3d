/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:27:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/24 23:59:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "cub3d_types.h"
# define TILE_SIZE 64

uint8_t	init_raycasting(t_cub3d *c3d);
int		init_sprites(t_cub3d *c3d);
int		draw_sprite(t_sprite *sprite, size_t i, t_cub3d *c3d);
void	render_sprite_projection(t_cub3d *c3d);
void	cast_rays(t_graphics *gfx, t_player *player, t_map_data *mapdat);
float	get_horz_distance(t_ray *ray, t_player *player, t_map_data *mapdat);
float	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat);
void	render_walls(t_graphics *gfx, int *colors);
void	render_aim(t_graphics *gfx);
void	update(t_cub3d *c3d);
int		render(t_cub3d *c3d);

uint8_t	is_ray_facing_left(t_ray *ray);
uint8_t	is_ray_facing_right(t_ray *ray);
uint8_t	is_ray_facing_top(t_ray *ray);
uint8_t	is_ray_facing_bot(t_ray *ray);

#endif /* RAYCASTING_H */
