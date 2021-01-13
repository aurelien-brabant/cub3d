/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:35:21 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/13 01:24:54 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "misc.h"

#include "libft/string.h"
#include "libft/dvector.h"
#include "libft/io.h"

bool	check_no_sp_near(uint8_t *row, size_t row_ind
							, size_t col_ind, t_dvec *map)
{
	size_t		max_row_ind; 
	size_t		max_col_ind;
	uint8_t		*prev;
	uint8_t		*next;

	max_row_ind = map->len - 1;
	max_col_ind = ft_strlen((const char *)row) - 1;
	if (col_ind == 0 || col_ind == max_col_ind || row_ind == 0
		|| row_ind == max_row_ind)
		return (false);
	prev = (uint8_t *)ft_dvec_get(map, row_ind - 1);
	next = (uint8_t *)ft_dvec_get(map, row_ind + 1);
	return(!(
		ft_strlen((char *) prev) <= col_ind
		|| ft_strlen((char *) next) <= col_ind
		|| row[col_ind - 1] == ' '
		|| row[col_ind + 1] == ' '
		|| prev[col_ind] == ' '
		|| next[col_ind] == ' '
		));
}

bool	check_parse_map(t_cub3d *c3d)
{
	size_t	i;
	size_t	j;
	uint8_t	*row;

	i = 0;
	while (i < c3d->dat.map.len)
	{
		row = (uint8_t *) ft_dvec_get(&c3d->dat.map, i);
		j = 0;
		while (row[j])
		{
			if (row[j] != '1' && row[j] != ' '
				&& !check_no_sp_near(row, i, j, &c3d->dat.map))
				ft_snprintf(c3d->err, ERR_LEN, "The map format is invalid");
			++j;
		}
		++i;
	}
	return (c3d->err[0] == '\0');
}
