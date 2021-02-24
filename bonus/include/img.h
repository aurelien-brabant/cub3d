/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:05:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 20:04:30 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H
# include "cub3d_types.h"

int		init_img(t_cub3d *c3d);
void	destroy_img(t_cub3d *c3d);
void	img_pix_put(t_img *img, int x, int y, int color);
int		img_pix_get(t_img *img, int x, int y);
void	draw_rect(t_img *img, t_rect rect, int color);

#endif /* IMG_H */
