/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:16:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/13 18:48:30 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_types.h"
#include "mlx.h"

#include "libft/string.h"
#include "cub3d_gfx.h"

static	void clear_img(t_img *img, t_map_data *mapdat)
{
	draw_rect(img, (t_rect){0, 0, mapdat->win_width, mapdat->win_height, 0, 0}, 0xFF);
}

int	render(t_cub3d *c3d)
{
	t_img	*draw_img;

	update(c3d);
	draw_img = &c3d->gfx.dpimg[1];
	clear_img(draw_img, &c3d->mapdat);
	render_walls(&c3d->gfx, &c3d->mapdat, &c3d->gamedat.player);
	render_minimap(c3d->mapdat.map, draw_img);
	render_player(draw_img, &c3d->gamedat.player);
	render_rays(&c3d->gamedat.player, &c3d->gfx);
	mlx_string_put(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr, 0, 0, 0xFF00, "cub3D - alpha");
	ft_memcpy(c3d->gfx.dpimg[0].addr, c3d->gfx.dpimg[1].addr,
			c3d->mapdat.win_height * c3d->gfx.dpimg[1].line_len);
	mlx_put_image_to_window(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr,
			c3d->gfx.dpimg[1].mlx_img, 0, 0);
	return (0);
}
