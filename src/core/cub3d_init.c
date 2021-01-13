/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:16:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/13 21:08:26 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "parsing.h"
#include "libft/string.h"
#include "libft/io.h"
#include "libft/dvector.h"

void	cub3d_init(t_cub3d *c3d)
{
	ft_memset(c3d, 0, sizeof(*c3d));
	c3d->state = ST_INITIALIZING;
	c3d->dotcub_fd = -1;
	ft_dvec_make(&c3d->gc, GARBAGE_COLLECTOR_INIT_COUNT);
	if (c3d->gc.val == NULL)
		ft_snprintf(c3d->err, ERR_LEN,
			"Could not initialize the garbage collector properly.");
	ft_dvec_make(&c3d->dat.map, MAP_INIT_COUNT);
	if (c3d->dat.map.val == NULL)
		ft_snprintf(c3d->err, ERR_LEN,
			"Could not initialize the map vector properly.");
	c3d->dat.col[P_ID_F - P_ID_F] = -1;
	c3d->dat.col[P_ID_C - P_ID_F] = -1;
	c3d->dat.player.x = -1.0;
	c3d->dat.player.y = -1.0;
	cub3d_shift_state(c3d, NULL);
}
