/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_gfx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:30:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/14 16:46:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** All the stuff needed for graphics
*/

#ifndef CUB3D_GFX_H
# define CUB3D_GFX_H
# include "cub3d_types.h"

int		init_gfx(t_cub3d *c3d);
void	destroy_gfx(t_graphics *gfx);

/*
*******************************************************************************
** DRAWING FUNCTIONS                                                         **
*******************************************************************************
*/

void	img_pix_put(t_img *img, int x, int y, int color);
void	draw_rect(t_img *img, t_rect rect, int color);
void	draw_line(t_img *img, t_line line, int color);
void	draw_circle(t_img *img, int x, int y, int radius);

/*
*******************************************************************************
** RENDER FUNCTIONS                                                          **
*******************************************************************************
*/

/* Update player location, cast the rays before rendering */
void	update(t_cub3d *c3d);

/* The general render function, handles update and render */
int		render(t_cub3d *c3d);

/* Render the rays on the MINIMAP, as lines */
void	render_rays(t_player *player, t_graphics *gfx);

/* Render the minimap as a grid */
void	render_minimap(t_vector map, t_img *img);

/* Render the player on the minimap, as a circle */
void	render_player(t_img *img, t_player *player);

/* Render the "3D" projection of the walls */
void	render_walls(t_graphics *gfx, t_map_data *mapdat, t_player *player);

/*
*******************************************************************************
** RAYCASTING FUNCTIONS                                                      **
*******************************************************************************
*/

void	cast_rays(t_graphics *gfx, t_player *player, t_map_data *mapdat);

/*
** Find the ray's horizontal intersection with a wall, and return the distance
** between it and the player
*/

double	get_horz_distance(t_ray *ray, t_player *player, t_map_data *mapdat);

/*
** Find the ray's vertical intersection with a wall, and return the distance
** between it and the player
*/

double	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat);


/*
*******************************************************************************
** EVENT HANDLING FUNCTIONS                                                  **
*******************************************************************************
*/

int		handle_keypress(int keysym, t_cub3d *c3d);
int		handle_keyrelease(int keysym, t_cub3d *c3d);
int		handle_mouse(int button, int x, int y, t_cub3d *c3d);

/*
*******************************************************************************
** GFX UTIL FUNCTIONS                                                        **
*******************************************************************************
*/

/*
** A simple pythagores theorem application to get the distance between
** two points.
*/

double	get_points_dist(double x1, double y1, double x2, double y2);

/*
** Degrees to radians conversion and vice-versa
*/

double	deg2rad(double deg);
double	rad2deg(double rad);

#endif
