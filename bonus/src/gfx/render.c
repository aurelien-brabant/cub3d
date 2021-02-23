/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:16:47 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 18:28:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "cub3d_gfx.h"

#include "bmp.h"

#include "libft/string.h"
#include "libft/io.h"

/*
** NOTE:
** The return value has no particular meaning.
** It is used to respect the mlx_hook_loop parameters.
*/

int	render(t_cub3d *c3d)
{
	t_img	*img;

	update(c3d);
	img = &c3d->gfx.dpimg;
	render_walls(&c3d->gfx, c3d->mapdat.col);
	render_sprite_projection(c3d);
	render_aim(&c3d->gfx);
	mlx_put_image_to_window(c3d->gfx.mlx_ptr, c3d->gfx.win_ptr,
			img->mlx_img, 0, 0);
	return (0);
}
