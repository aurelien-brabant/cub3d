/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 03:02:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/21 22:04:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "cub3d_gfx.h"

#include "libft/core.h"

/*
** Functions used to initialize mlx_image related stuff, for textures and
** frame buffering.
** Separated from the init_gfx file to make the code norme compliant.
*/

static int	init_dpimg(t_graphics *gfx)
{
	t_img	*img;

	img = &gfx->dpimg;
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
	mlx_destroy_image(gfx->mlx_ptr, gfx->dpimg.mlx_img);
	while (i < 5)
	{
		if (gfx->teximg[i].mlx_img != NULL)
			mlx_destroy_image(gfx->mlx_ptr, gfx->teximg[i++].mlx_img);
	}
	if (gfx->visible_sprites != NULL)
		ft_vec_destroy(gfx->visible_sprites, NULL);
	if (gfx->sprites != NULL)
		ft_vec_destroy(gfx->sprites, &free);
}

int	init_img(t_graphics *gfx, t_map_data *mapdat)
{
	if (!init_dpimg(gfx) || !init_teximg(gfx, mapdat)
		|| !init_sprites(gfx, mapdat))
		return (0);
	return (1);
}
