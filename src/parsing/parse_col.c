/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:53:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 12:01:53 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_types.h"
#include "cub3d_misc.h"
#include "cub3d_msg.h"

#include "libft/string.h"
#include "libft/io.h"
#include "libft/strconv.h"


static bool	conv_strs(char **col_str, int *col, char *key, char *err)
{
	uint8_t	i;

	i = -1;
	while (++i < 3)
	{
		if (!is_parsable_nb(col_str[i]))
		{
			ft_snprintf(err, ERR_LEN, MSG_NAN, key, col_str[i]);
			return (false);
		}
	}
	i = -1;
	while (++i < 3)
	{
		col[i] = ft_atoi(col_str[i]);
		if (col[i] > 255)
		{
			ft_snprintf(err, ERR_LEN, MSG_OVER_RGB, key, col[i]);
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
			col_str[i] = tok;
		if (i == 1)
			tok = ft_strtok(NULL, "\0");
		else
			tok = ft_strtok(NULL, ",");
		++i;
	}
	if (i > 3)
		ft_snprintf(c3d->err, ERR_LEN, MSG_BAD_ARG_NB, key, 3, i + 1);
	else if (conv_strs(col_str, col, key, c3d->err))
		c3d->mapdat.col[id - P_ID_F] = make_rgb(col[0], col[1], col[2]);
}
