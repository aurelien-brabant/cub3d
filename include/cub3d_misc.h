/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_misc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:37:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 12:00:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MISC_H
# define CUB3D_MISC_H
# include <stddef.h>
# include "libft/vector.h"

int	is_parsable_nb(char *nb_str);

int	make_rgb(int red, int green, int blue);

uint8_t	map(t_vector *map, size_t x, size_t y);

#endif
