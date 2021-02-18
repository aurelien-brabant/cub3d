/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 03:02:11 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/18 02:05:09 by abrabant         ###   ########.fr       */
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

static int	init_dpimg(t_graphics *gfx, t_map_data *mapdat)
{
	uint8_t	i;
	t_img	*img;

	i = 0;
	while (i < 2)
	{
		img = &gfx->dpimg[i];
		img->mlx_img = mlx_new_image(gfx->mlx_ptr, mapdat->win_width,
				mapdat->win_height);
		img->width = mapdat->win_width;
		img->height = mapdat->win_height;
		if (img->mlx_img == NULL)
			return (0);
		img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
				&img->line_len, &img->endian);
		++i;
	}
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
	while (i < 7)
	{
		if (i < 2 && gfx->dpimg[i].mlx_img != NULL)
			mlx_destroy_image(gfx->mlx_ptr, gfx->dpimg[i].mlx_img);
		else if (i < 7 && gfx->teximg[i - 2].mlx_img != NULL)
			mlx_destroy_image(gfx->mlx_ptr, gfx->teximg[i - 2].mlx_img);
		++i;
	}
	if (gfx->visible_sprites != NULL)
		ft_vec_destroy(gfx->visible_sprites, NULL);
	if (gfx->sprites != NULL)
		ft_vec_destroy(gfx->sprites, &free);
}

int	init_img(t_graphics *gfx, t_map_data *mapdat)
{
	if (!init_dpimg(gfx, mapdat) || !init_teximg(gfx, mapdat)
		|| !init_sprites(gfx, mapdat))
		return (0);
	return (1);
}
