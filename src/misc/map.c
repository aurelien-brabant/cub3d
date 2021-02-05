/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:54:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 12:41:45 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"

#include "libft/vector.h"

/*
** This is basically a shortcut to write less code
** to access the map's content.
** If parametrized macros were allowed by the norm,
** it would be better to use them tho.
*/

uint8_t	getmapc(t_vector *map, size_t x, size_t y)
{
	return (((uint8_t *)ft_vec_get(map, y))[x]);
}
