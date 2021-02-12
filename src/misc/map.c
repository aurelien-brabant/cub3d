/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:54:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/12 15:23:07 by abrabant         ###   ########.fr       */
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
	if (index >= ft_strlen((char *)row))
		return ('1');
	return (row[index]);
}
