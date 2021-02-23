/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_save_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:23:00 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/21 23:01:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "cub3d_core.h"
#include "cub3d_gfx.h"
#include "cub3d_types.h"
#include "bmp.h"

#include "libft/io.h"

static void	pix_fn(uint8_t *stream, uint8_t *bytes)
{
	*(int *)bytes = *(int *)stream;
}

int	render_save_bmp(t_cub3d *c3d)
{
	t_graphics	*gfx;
	t_bmp		*bmp;

	gfx = &c3d->gfx;
	update(c3d);
	render_walls(gfx, c3d->mapdat.col);
	render_sprite_projection(c3d);
	render_aim(gfx);
	bmp = bmp_new((uint8_t *)gfx->dpimg.addr, gfx->win_width,
			gfx->win_height, gfx->dpimg.bpp);
	if (bmp == NULL)
		return (!ft_snprintf(c3d->err, ERR_LEN, "Failed to init bmp."));
	ft_printf("Encoding first frame rendering to \033[0;33m%s\033[0m\n",
			c3d->screenshot_name);
	if (!bmp_encode_file(bmp, c3d->screenshot_name, &pix_fn, BMP_EM_REVERSE))
	{
		free(bmp);
		return (!ft_snprintf(c3d->err, ERR_LEN, "Failed to create bmp file."));
	}
	ft_putstr_fd(".bmp file created successfully.\n", STDOUT_FILENO);
	free(bmp);
	cub3d_shift_state(c3d, NULL);
	return (1);
}
