/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:47:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/12 16:37:18 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "core.h"

void	parse_id(t_cub3d *c3d);
void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key);
void	parse_res(t_cub3d *c3d);
void	parse_col(t_cub3d *c3d, int id, char *key);
void	parse_map(t_cub3d *c3d);
bool	check_parse_id(t_cub3d *c3d);
bool	check_parse_map(t_cub3d *c3d);

#endif