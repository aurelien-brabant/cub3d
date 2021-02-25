/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:37:25 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 20:05:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H
# include "cub3d_types.h"

int				is_parsable_nb(char *nb_str);

int				make_rgb(int red, int green, int blue);

unsigned char	map_getchar(t_vector map, float x, float y);
uint8_t			map_has_wall_at(t_vector map, float x, float y);
uint8_t			map_is_legal(t_vector map, float x, float y);

void			c3d_warn(const char *msg);
void			c3d_info(const char *msg);

#endif /* MISC_H */
