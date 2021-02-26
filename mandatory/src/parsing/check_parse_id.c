/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:14:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 18:13:29 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_types.h"

/*
** Make sure that all the identifiers have been parsed.
** Used as a checker when calling cub3d_shift_state.
*/

bool	check_parse_id(t_cub3d *c3d)
{
	unsigned char	i;

	i = 0;
	while (i < P_ID_S)
		if (!c3d->mapdat.textures[i++])
			return (0);
	i = 0;
	while (i <= P_ID_C - P_ID_F)
		if (c3d->mapdat.col[i++] < 0)
			return (0);
	return (c3d->mapdat.win_width > 0 && c3d->mapdat.win_height > 0);
}
