/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:17:41 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 23:56:29 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_types.h"
#include "misc.h"
#include "msg.h"
#include "libft/strconv.h"
#include "libft/cstring.h"
#include "libft/io.h"

static bool	convert_nbrs(char **nb_str, int *nb, char *err)
{
	size_t	i;

	i = 0;
	while (err[0] == '\0' && i < 2)
	{
		if (!is_parsable_nb(nb_str[i]))
			ft_snprintf(err, ERR_LEN, MSG_NAN, "R", nb_str[i]);
		else
		{
			nb[i] = ft_atoi(nb_str[i]);
			if (nb[i] == 0)
				ft_snprintf(err, ERR_LEN, MSG_RES_ZERO);
		}
		++i;
	}
	return (err[0] == '\0');
}

void	parse_res(t_cub3d *c3d)
{
	char		*nb_str[2];
	int			nb[2];
	uint8_t		i;
	char		*tok;

	i = 0;
	tok = ft_strtok(NULL, " ");
	while (tok != NULL)
	{
		if (i <= 1)
			nb_str[i] = tok;
		tok = ft_strtok(NULL, " ");
		++i;
	}
	if (i != 2)
		ft_snprintf(c3d->err, ERR_LEN, MSG_BAD_ARG_NB, "R", 2, i);
	else if (convert_nbrs(nb_str, nb, c3d->err))
	{
		c3d->mapdat.win_width = nb[0];
		c3d->mapdat.win_height = nb[1];
	}
}
