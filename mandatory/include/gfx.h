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
float	get_points_dist(float x1, float y1, float x2, float y2);
float	deg2rad(float deg);
float	rad2deg(float rad);
float	normalize_angle(float angle);

#endif /* GFX_H */
