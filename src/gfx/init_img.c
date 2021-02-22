/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 03:02:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 16:41:49 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "cub3d_types.h"
#include "mlx.h"

#include "cub3d_gfx.h"

#include "libft/core.h"
#include "libft/io.h"

/*
** Functions used to initialize mlx_image related stuff, for textures and
** frame buffering.
** Separated from the init_gfx file to make the code norme compliant.
*/

static int	init_save_img(t_graphics *gfx, t_img *img, char *err)
{
	char	*msg;
	size_t	alloc_size;

	msg = "Could not allocate pixel buffer: alloc size overflow detected."; 
	img->bpp = 32;
	img->height = gfx->win_height;
	img->width = gfx->win_width;
	img->line_len = 4 * gfx->win_width;
	img->endian = (uint8_t)0x100;
	if (img->line_len / 4 != gfx->win_width)
		return (!ft_snprintf(err, ERR_LEN, msg));
	alloc_size = img->line_len * gfx->win_height;
	if (alloc_size / gfx->win_height != (size_t)img->line_len)
		return (!ft_snprintf(err, ERR_LEN, msg));
	img->addr = ft_calloc(alloc_size, 1);
	if (img->addr != NULL)
		return (1);
	return (!ft_snprintf(err, ERR_LEN, msg));
}

static int	init_dpimg(t_cub3d *c3d)
{
	t_img		*img;
	t_graphics	*gfx;

	gfx = &c3d->gfx;
	img = &gfx->dpimg;
	if (c3d->opt & OPT_SAVE)
		return (init_save_img(gfx, img, c3d->err));
	img->mlx_img = mlx_new_image(gfx->mlx_ptr, gfx->win_width,
			gfx->win_height);
	img->width = gfx->win_width;
	img->height = gfx->win_height;
	if (img->mlx_img == NULL)
		return (0);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	return (1);
}

static int	init_teximg(t_graphics *gfx, t_map_data *mapdat)
{
	uint8_t	i;
	t_img	*img;

	i = 0;
	while (i < 5)
	{
		img = &gfx->teximg[i];
		img->mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
				mapdat->textures[i], &img->width, &img->height);
		if (img->mlx_img == NULL)
			return (0);
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
				&img->line_len, &img->endian);
		++i;
	}
	return (1);
}

void	destroy_img(t_graphics *gfx)
{
	uint8_t	i;

	i = 0;
	if (gfx->dpimg.mlx_img)
		mlx_destroy_image(gfx->mlx_ptr, gfx->dpimg.mlx_img);
	while (i < 5)
	{
		if (gfx->teximg[i].mlx_img != NULL)
			mlx_destroy_image(gfx->mlx_ptr, gfx->teximg[i].mlx_img);
		++i;
	}
	if (gfx->visible_sprites != NULL)
		ft_vec_destroy(gfx->visible_sprites, NULL);
	if (gfx->sprites != NULL)
		ft_vec_destroy(gfx->sprites, &free);
}

int	init_img(t_cub3d *c3d, t_map_data *mapdat)
{
	if (!init_dpimg(c3d)
		|| !init_teximg(&c3d->gfx, mapdat)
		|| !init_sprites(&c3d->gfx, mapdat))
		return (0);
	return (1);
}
