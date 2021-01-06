/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:16:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 15:43:04 by abrabant         ###   ########.fr       */
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
	if (!ft_dvec_make(&c3d->gc, GARBAGE_COLLECTOR_INIT_COUNT))
		ft_snprintf(c3d->err, ERR_LEN, 
			"Could not initialize the garbage collector properly.");
	c3d->dat.col[P_ID_F - P_ID_F] = -1;
	c3d->dat.col[P_ID_C - P_ID_F] = -1;
	cub3d_shift_state(c3d, NULL);
}
