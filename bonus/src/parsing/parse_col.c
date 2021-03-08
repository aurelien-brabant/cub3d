/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:53:53 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 21:33:53 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_types.h"
#include "misc.h"
#include "msg.h"
#include "libft/cstring.h"
#include "libft/io.h"
#include "libft/strconv.h"

static uint8_t	conv_strs(char **col_str, int *col, char *key, char *err)
{
	uint8_t	i;

	i = -1;
	while (++i < 3)
	{
		if (!is_parsable_nb(col_str[i]))
			return (!ft_snprintf(err, ERR_LEN, MSG_NAN, key, col_str[i]));
	}
	i = 0;
	while (i < 3)
	{
		col[i] = ft_atoi(col_str[i]);
		if (col[i] > 255)
			return (!ft_snprintf(err, ERR_LEN, MSG_OVER_RGB, key, col[i]));
		++i;
	}
	return (1);
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
