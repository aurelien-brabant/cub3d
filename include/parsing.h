/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:47:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 00:28:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "core.h"

void	parse_id(t_cub3d *c3d);
void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key);
void	parse_res(t_cub3d *c3d);
bool	check_parse_id(t_cub3d *c3d);

#endif
