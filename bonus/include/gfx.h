/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 16:30:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 20:17:29 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H
# include "cub3d_types.h"

int		init_gfx(t_cub3d *c3d);
void	destroy_gfx(t_graphics *gfx);
double	get_points_dist(double x1, double y1, double x2, double y2);
double	deg2rad(double deg);
double	rad2deg(double rad);
double	normalize_angle(double angle);

#endif /* GFX_H */
