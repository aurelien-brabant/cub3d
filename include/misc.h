/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:37:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/13 21:07:30 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H
# include "libft/dvector.h"

/*
** gc.c 
*/

void	*gc_put(t_dvec *gc, void *el);

/*
** parsing_utils.c
*/

bool	is_parsable_nb(char *nb_str);

/*
** color.c
*/

int		make_rgb(int red, int green, int blue);

/*
** map.c
*/

uint8_t	getmapc(t_dvec *map, size_t x, size_t y);

#endif
