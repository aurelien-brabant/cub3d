/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:16:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/21 15:41:38 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "cub3d_gfx.h"

#include "bmp.h"

#include "libft/string.h"
#include "libft/io.h"

static void	pix_fn(uint8_t *stream, uint8_t *bytes)
{
	*(int *)bytes = *(int *)stream;
}

static void	save_to_bmp(t_cub3d *c3d, t_img *draw_img)
{
	t_bmp	*bmp;

	bmp = bmp_new((uint8_t *)draw_img->addr, draw_img->width,
			draw_img->height, draw_img->bpp);
	ft_printf("Encoding first render into \033[0;33m%s\033[0m...\n",
			c3d->screenshot_name);
	bmp_encode_file(bmp, c3d->screenshot_name, &pix_fn, BMP_EM_REVERSE);
	free(bmp);
	mlx_loop_end(c3d->gfx.mlx_ptr);
}

int	render(t_cub3d *c3d)
{
	t_img	*img;

	update(c3d);
	img = &c3d->gfx.dpimg;
	render_walls(&c3d->gfx, &c3d->mapdat, &c3d->gfx.player);
	render_sprite_projection(c3d);
	render_aim(&c3d->gfx);
	if (c3d->opt & OPT_SAVE)
	{
		save_to_bmp(c3d, img);
		return (0);
	}
	mlx_put_image_to_window(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr,
			img->mlx_img, 0, 0);
	return (0);
}
