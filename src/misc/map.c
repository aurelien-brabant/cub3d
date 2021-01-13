/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:54:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/12 22:11:19 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

#include "libft/dvector.h"

/*
** This is basically a shortcut to write less code
** to access the map's content.
** If parametrized macros were allowed by the norm,
** it would be better to use them tho.
*/

uint8_t	getmapc(t_dvec *map, size_t x, size_t y)
{
	return (((uint8_t *)ft_dvec_get(map, y))[x]);
}
