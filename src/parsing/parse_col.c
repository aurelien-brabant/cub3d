/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:53:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 15:33:00 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft/string.h"
#include "libft/io.h"
#include "libft/strconv.h"

#include "core.h"
#include "misc.h"

static bool	conv_strs(char **col_str, int *col, char *key, char *err)
{
	uint8_t	i;

	i = -1;
	while (++i < 3)
	{
		if (!is_parsable_nb(col_str[i]))
		{
			ft_snprintf(err, ERR_LEN, 
				"%s: \"%s\": nb could not be parsed.", key, col_str[i]);
			return (false);
		}
	}
	i = -1;
	while (++i < 3)
	{
		col[i] = ft_atoi(col_str[i]);
		if (col[i] > 255)
		{
			ft_snprintf(err, ERR_LEN, "%s: %d: greater than 255.", key, col[i]);
			return (false);
		}
	}
	return (true);
}


void	parse_col(t_cub3d *c3d, t_parsing_id id, char *key)
{
	char			*tok;
	char			*col_str[3];
	int				col[3];
	size_t			i;

	i = 0;
	tok = ft_strtok(NULL, ",");
	while (tok)
	{
		if (i <= 2)
			col_str[i++] = tok;
		tok = ft_strtok(NULL, ",");
	}
	if (i > 3)
		ft_snprintf(c3d->err, ERR_LEN, 
			"%s: Expected 3 arguments, found %d", key, i + 1);
	else if (conv_strs(col_str, col, key, c3d->err))
		c3d->dat.col[id - P_ID_F] = make_rgb(col[0], col[1], col[2]);
}
