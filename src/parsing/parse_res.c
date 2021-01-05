/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:17:41 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 00:42:42 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"
#include "libft/strconv.h"
#include "libft/string.h"
#include "libft/io.h"

#include "core.h"

static bool	is_valid_nb(char *tok)
{
	while (*tok)
		if (!ft_isdigit(*tok++))
			return (false);
	return (true);
}

void	parse_res(t_cub3d *c3d)
{
	char	*nb_str[2]; 
	int		nb[2];

	nb_str[0] = ft_strtok(NULL, " \t");
	nb_str[1] = ft_strtok(NULL, " \t");
	if (!nb_str[0] || !nb_str[1])
		ft_snprintf(c3d->err, ERR_LEN, "R: expects two tokens, found %d.",
			(nb_str[0] != NULL) + (nb_str[1] != NULL));
	else if (!is_valid_nb(nb_str[0]) || !is_valid_nb(nb_str[1]))
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
