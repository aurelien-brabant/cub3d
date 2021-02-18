/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 01:05:16 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/18 02:06:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/core.h"

#include "cub3d_types.h"

/*
** For the mandatory part, sprites all have the same texture.
** This texture is stored in gfx->teximg[4].
*/

static t_sprite	*sprite_new(double x, double y)
{
	t_sprite	*sprite;

	x = x * TILE_SIZE + (TILE_SIZE / 2.0);
	y = y * TILE_SIZE + (TILE_SIZE / 2.0);
	sprite = ft_calloc(1, sizeof (*sprite));
	if (sprite == NULL)
		return (NULL);
	sprite->x = x;
	sprite->y = y;
	return (sprite);
}

static int	process_map_row(char *row, size_t rowi, t_vector sprites)
{
	size_t	coli;

	coli = 0;
	while (row[coli] != '\0')
	{
		if (row[coli] == '2' && ft_vec_add(sprites,
				sprite_new(coli, rowi)) == NULL)
			return (1);
		++coli;
	}
	return (0);
}

int	init_sprites(t_graphics *gfx, t_map_data *mapdat)
{
	gfx->sprites = ft_vec_new(0, 0);
	if (gfx->sprites == NULL)
		return (0);
	if (ft_vec_foreach(mapdat->map, &process_map_row, gfx->sprites) != 0)
		return (0);
	gfx->visible_sprites = ft_vec_new(ft_vec_len(gfx->sprites), 0);
	return (gfx->visible_sprites != NULL);
}
