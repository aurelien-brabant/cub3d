/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:54:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 02:21:51 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/Xlib.h>
#include <math.h>

#include "config.h"

#include "cub3d_core.h"
#include "libft/vector.h"
#include "libft/string.h"

unsigned char	map_getchar(t_vector map, double x, double y)
{
	const unsigned char	*row;
	size_t				index;

	row = ft_vec_get(map, (size_t)floor(y / TILE_SIZE));
	index = floor(x / TILE_SIZE);
	if (row == NULL)
		return ('1');
	if (index >= ft_strlen((char *)row))
		return ('1');
	return (row[index]);
}

uint8_t	map_has_wall_at(t_vector map, double x, double y)
{
	unsigned char	c;

	c = map_getchar(map, x, y);
	return (c == '1' || c == ' ');
}

uint8_t	map_is_legal(t_vector map, double x, double y)
{
	const unsigned char	*row;
	size_t				index;

	row = ft_vec_get(map, (size_t)floor(y / TILE_SIZE));
	index = floor(x / TILE_SIZE);
	if (row == NULL)
		return (0);
	if (index >= ft_strlen((char *)row))
		return (0);
	return (1);
}
