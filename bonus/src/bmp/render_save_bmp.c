/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_save_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:23:00 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 00:31:32 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "cub3d.h"
#include "cub3d_types.h"
#include "gfx.h"
#include "bmp.h"
#include "raycasting.h"
#include "libft/io.h"

/*
** Handles little as well as big endians
*/

static void	pix_fn(uint8_t *stream, uint8_t *bytes, int bpp)
{
	uint8_t	i;
	uint8_t	j;

	i = 0;
	j = 0;
	while (i < bpp / 8)
	{
		j = i;
		if ((uint8_t) 0x100 != 0)
			j = bpp / 8 - 1 - i;
		bytes[i] = stream[j];
		++i;
	}
}

bool	render_save_bmp(t_cub3d *c3d)
{
	t_graphics	*gfx;
	t_bmp		*bmp;

	gfx = &c3d->gfx;
	update(c3d);
	draw_walls(gfx, c3d->mapdat.col);
	draw_sprite_projection(c3d);
	draw_aim(gfx);
	bmp = bmp_new((uint8_t *)gfx->dpimg.addr, gfx->win_width,
			gfx->win_height, gfx->dpimg.bpp);
	if (bmp == NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, "Failed to init bmp.");
		return (false);
	}
	if (!bmp_encode_file(bmp, c3d->screenshot_name, &pix_fn, BMP_EM_REVERSE))
	{
		free(bmp);
		ft_snprintf(c3d->err, ERR_LEN, "Failed to create bmp file.");
		return (false);
	}
	ft_putstr_fd(".bmp file created successfully.\n", STDOUT_FILENO);
	free(bmp);
	cub3d_shift_state(c3d, NULL);
	return (true);
}
