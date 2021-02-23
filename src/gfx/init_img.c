/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 03:02:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 01:24:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"

#include "cub3d_msg.h"
#include "cub3d_gfx.h"

#include "libft/core.h"
#include "libft/io.h"

/*
** Functions used to initialize mlx_image related stuff, for textures and
** frame buffering.
** Separated from the init_gfx file to make the code norme compliant.
*/

/*
** Doesn't use mlx_image as a pixel buffer for the save operation
** as nothing needs to be displayed on the screen.
** Use the bpp and the endian parameters of a texture image.
*/

static int	init_save_img(t_graphics *gfx, t_img *img, char *err)
{
	size_t	alloc_size;

	img->bpp = gfx->teximg[0].bpp;
	img->height = gfx->win_height;
	img->width = gfx->win_width;
	img->line_len = (img->bpp / 8) * gfx->win_width;
	img->endian = gfx->teximg[0].endian;
	if (img->line_len / (img->bpp / 8) != gfx->win_width)
		return (!ft_snprintf(err, ERR_LEN, MSG_SAVE_BADALLOC));
	alloc_size = img->line_len * gfx->win_height;
	if (alloc_size / gfx->win_height != (size_t)img->line_len)
		return (!ft_snprintf(err, ERR_LEN, MSG_SAVE_BADALLOC));
	img->addr = ft_calloc(alloc_size, 1);
	if (img->addr != NULL)
		return (1);
	return (!ft_snprintf(err, ERR_LEN, MSG_SAVE_BADALLOC));
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
		return (!ft_snprintf(c3d->err, ERR_LEN, MSG_MLX_IMG_FAILED));
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	return (1);
}

static int	init_teximg(t_cub3d *c3d)
{
	t_graphics	*gfx;
	t_map_data	*mapdat;
	t_img		*img;
	uint8_t		i;

	gfx = &c3d->gfx;
	mapdat = &c3d->mapdat;
	i = 0;
	while (i < 5)
	{
		img = &gfx->teximg[i];
		img->mlx_img = mlx_xpm_file_to_image(gfx->mlx_ptr,
				mapdat->textures[i], &img->width, &img->height);
		if (img->mlx_img == NULL)
			return (!ft_snprintf(c3d->err, ERR_LEN, MSG_MLX_IMG_FAILED));
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
				&img->line_len, &img->endian);
		++i;
	}
	return (1);
}

void	destroy_img(t_cub3d *c3d)
{
	t_graphics	*gfx;
	uint8_t		i;

	gfx = &c3d->gfx;
	i = 0;
	if (c3d->opt & OPT_SAVE)
		free(gfx->dpimg.addr);
	else if (gfx->dpimg.mlx_img)
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

int	init_img(t_cub3d *c3d)
{
	if (!init_teximg(c3d)
		|| !init_dpimg(c3d)
		|| !init_sprites(c3d))
		return (0);
	return (1);
}
