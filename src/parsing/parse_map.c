/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:45:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/13 00:13:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "parsing.h"
#include "misc.h"

#include "libft/io.h"
#include "libft/string.h"
#include "libft/dvector.h"

static void	check_line(char *line, char *err)
{
	char	*ptr;

	while (err[0] == '\0' && *line != '\0')
	{
		ptr = ft_strchr("012NESW ", *line);
		if (ptr == NULL)
			ft_snprintf(err, ERR_LEN,
				"\"%c\" character is not allowed in map definition.", *line);
		++line;
	}
}

void	parse_map(t_cub3d *c3d)
{
	char	*line;
	int		ret;
	
	ret = ft_gnl(c3d->dotcub_fd, &line);
	gc_put(&c3d->gc, line);
	if (ret <= 0)
	{
		if (ret == 0 && ft_strlen(line) == 0)
			cub3d_shift_state(c3d, &check_parse_map);
		else
			ft_snprintf(c3d->err, ERR_LEN,
				"An unexpected error occured with GNL");
		return ;
	}
	if (ft_strlen(line) == 0)
	{
		if (ft_dvec_get(&c3d->dat.map, 0) != NULL)
			ft_snprintf(c3d->err, ERR_LEN,
				"Found an empty line after the beginning of the map.");
		return ;
	}
	check_line(line, c3d->err);
	if (c3d->err[0] == '\0')
		ft_dvec_add(&c3d->dat.map, line);
}