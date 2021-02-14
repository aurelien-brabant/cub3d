/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_misc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:37:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/14 16:46:14 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MISC_H
# define CUB3D_MISC_H
# include <stddef.h>
# include "libft/vector.h"

int				is_parsable_nb(char *nb_str);

int				make_rgb(int red, int green, int blue);

unsigned char	map_getchar(t_vector map, double x, double y);
int				map_has_wall_at(t_vector map, double x, double y);


#endif
