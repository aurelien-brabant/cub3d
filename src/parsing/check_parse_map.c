/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:35:21 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 01:10:30 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/vector.h"
#include "libft/io.h"

#include "cub3d_core.h"
#include "cub3d_msg.h"
#include "cub3d_parsing.h"

/*
** Ensure that a non-wall map character is always surrounded
** by a non-space one. This simple rule will force the whole map
** to be surrounded by walls, that are basically the barrier between
** spaces (i.e the outside of the map) and the map's content.
** Spaces are NOT allowed inside the map, that's considered as a map
** error.
*/

int	is_sp_near(char *row, size_t row_ind, size_t col_ind, t_vector map)
{
	size_t		max_row_ind;
	size_t		max_col_ind;
	char		*prev;
	char		*next;

	max_row_ind = ft_vec_len(map);
	max_col_ind = ft_strlen((const char *)row) - 1;
	if (col_ind == 0 || col_ind == max_col_ind || row_ind == 0
		|| row_ind == max_row_ind)
		return (0);
	prev = ft_vec_get(map, row_ind - 1);
	next = ft_vec_get(map, row_ind + 1);
	return (!(ft_strlen(prev) <= col_ind
			|| ft_strlen(next) <= col_ind
			|| row[col_ind - 1] == ' '
			|| row[col_ind + 1] == ' '
			|| prev[col_ind] == ' '
			|| next[col_ind] == ' '));
}

static int	check_spawn(t_player *p, size_t row_ind, size_t col_ind)
{
	if (p->x != -1.0 || p->y != -1.0)
		return (0);
	p->x = col_ind;
	p->y = row_ind;
	return (1);
}

static int	check_row(char *row, size_t i, t_cub3d *c3d)
{
	size_t	j;

	j = 0;
	while (c3d->err[0] == '\0' && row[j] != '\0')
	{
		if (!ft_strchr(" 1", row[j]) && !is_sp_near(row, i, j, c3d->mapdat.map))
			ft_snprintf(c3d->err, ERR_LEN, MSG_NO_WALL, i + 1, j + 1);
		if (ft_strchr("NESW", row[j]))
			if (!check_spawn(&c3d->gfx.player, i, j))
				ft_snprintf(c3d->err, ERR_LEN, MSG_SPAWN_REDEF);
		++j;
	}
	return (c3d->err[0] != '\0');
}

int	check_parse_map(t_cub3d *c3d)
{
	t_player	*player;

	player = &c3d->gfx.player;
	ft_vec_foreach(c3d->mapdat.map, &check_row, c3d);
	if (c3d->err[0] == '\0' && (player->x < 0 || player->y < 0))
		ft_snprintf(c3d->err, ERR_LEN, MSG_SPAWN_MISSING);
	return (c3d->err[0] == '\0');
}
