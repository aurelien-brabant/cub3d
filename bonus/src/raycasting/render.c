/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:16:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 17:20:41 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "gfx.h"
#include "raycasting.h"
#include "libft/cstring.h"
#include "libft/io.h"

int	render(t_cub3d *c3d)
{
	t_img	*img;
	char	fps_str[10];

	update(c3d);
	img = &c3d->gfx.dpimg;
	draw_walls(&c3d->gfx, c3d->mapdat.col);
	draw_sprite_projection(c3d);
	draw_aim(&c3d->gfx);
	mlx_put_image_to_window(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr,
			img->mlx_img, 0, 0);
	mlx_set_font(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr, "6x13");
	ft_snprintf(fps_str, 10, "FPS: %hhd", c3d->gfx.fps);
	mlx_string_put(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr, 20, 20, 0xFFFF00,
			fps_str);
	return (0);
}
