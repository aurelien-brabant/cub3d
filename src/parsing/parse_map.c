/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:45:51 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 14:03:10 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_core.h"
#include "cub3d_parsing.h"
#include "cub3d_msg.h"

#include "libft/io.h"
#include "libft/string.h"
#include "libft/vector.h"

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
	static bool	empty_flag = false;
	char		*line;
	int			ret;

	ret = ft_gnl(c3d->fildes, &line);
	ft_vec_add(c3d->gbc, line);
	if (ret == 0 && *line == '\0')
		cub3d_shift_state(c3d, &check_parse_map);
	else if (ret == -1)
		ft_snprintf(c3d->err, ERR_LEN, MSG_GNL_ERROR);
	else if (*line == '\0')
		empty_flag = true;
	else if (empty_flag && ft_vec_get(c3d->mapdat.map, 0) != NULL)
		ft_snprintf(c3d->err, ERR_LEN, MSG_EMPTY_LINE_MAP);
	else
	{
		check_line(line, c3d->err);
		empty_flag = false;
	}
	if (!empty_flag && c3d->err[0] == '\0')
		ft_vec_add(c3d->mapdat.map, line);
}
