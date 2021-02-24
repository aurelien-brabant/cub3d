/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:31:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 21:52:37 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "cub3d_types.h"

void	parse_id(t_cub3d *c3d);
void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key);
void	parse_res(t_cub3d *c3d);
void	parse_col(t_cub3d *c3d, int id, char *key);
void	parse_map(t_cub3d *c3d);
uint8_t	check_parse_id(t_cub3d *c3d);
uint8_t	check_parse_map(t_cub3d *c3d);

#endif /* PARSING_H */
