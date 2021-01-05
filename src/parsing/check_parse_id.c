/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:14:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/05 16:31:11 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "libft/types.h"

#include "core.h"

/*
** Make sure that all the identifiers have been parsed.
** Used as a checker when calling cub3d_shift_state.
**
** @PARAM	c3d	=> all the cub3d essential data.
*/

bool	check_parse_id(t_cub3d *c3d)
{
	unsigned char	i;

	i = 0;
	while (i <= P_ID_S - P_ID_RES)
		if (!c3d->dat.tex[i++])
			return (false);
	i = 0;
	while (i <= P_ID_C - P_ID_F)
		if (c3d->dat.col[i++] > UCHAR_MAX)
			return (false);
	return (c3d->dat.res.w > 0 && c3d->dat.res.h > 0);
}
