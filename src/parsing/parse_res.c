/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:17:41 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/13 21:13:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"
#include "libft/strconv.h"
#include "libft/string.h"
#include "libft/io.h"

#include "core.h"
#include "misc.h"
#include "msg.h"

static bool	convert_nbrs(char **nb_str, long long *nb, char *err)
{
	size_t	i;

	i = 0;
	while (err[0] == '\0' && i < 2)
	{
		if (!is_parsable_nb(nb_str[i]))
			ft_snprintf(err, ERR_LEN, MSG_NAN, "R", nb_str[i]);
		else
		{
			nb[i] = ft_btoll(nb_str[i], 10);
			if (nb[i] == 0)
				ft_snprintf(err, ERR_LEN, MSG_NAN);
		}
		++i;
	}
	return (err[0] == '\0');
}

void	parse_res(t_cub3d *c3d)
{
	char		*nb_str[2];
	long long	nb[2];
	size_t		i;
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
		c3d->dat.res.w = nb[0];
		c3d->dat.res.h = nb[1];
	}
}

/*
void	parse_res(t_cub3d *c3d)
{
	char	*nb_str[2]; 
	int		nb[2];

	nb_str[0] = ft_strtok(NULL, " \t");
	nb_str[1] = ft_strtok(NULL, " \t");
	if (!nb_str[0] || !nb_str[1])
		ft_snprintf(c3d->err, ERR_LEN, "R: expects two tokens, found %d.",
			(nb_str[0] != NULL) + (nb_str[1] != NULL));
	else if (!is_parsable_nb(nb_str[0]) || !is_parsable_nb(nb_str[1]))
		ft_snprintf(c3d->err, ERR_LEN, 
			"R: at least one of the token is not a valid number.", nb_str[0]);
	else
	{
		nb[0] = ft_atoi(nb_str[0]);
		nb[1] = ft_atoi(nb_str[1]);
		if (nb[0] == 0 || nb[1] == 0)
			ft_snprintf(c3d->err, ERR_LEN, "R: values must be higher than zero.");
		else
		{
			c3d->dat.res.w = nb[0];
			c3d->dat.res.h = nb[1];
		}
	}
}
*/
