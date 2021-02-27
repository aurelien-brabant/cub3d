/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:16:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 21:29:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "cub3d.h"
#include "libft/string.h"
#include "libft/io.h"
#include "libft/vector.h"

void	cub3d_init(t_cub3d *c3d)
{
	ft_memset(c3d, 0, sizeof(*c3d));
	c3d->state = ST_INITIALIZING;
	c3d->fildes = -1;
	c3d->gbc = ft_vec_new(20, 0);
	if (c3d->gbc == NULL)
		ft_snprintf(c3d->err, ERR_LEN,
			"Could not initialize the garbage collector properly.");
	c3d->mapdat.map = ft_vec_new(20, 0);
	if (c3d->mapdat.map == NULL)
		ft_snprintf(c3d->err, ERR_LEN,
			"Could not initialize the map vector properly.");
	c3d->mapdat.col[P_ID_F - P_ID_F] = -1;
	c3d->mapdat.col[P_ID_C - P_ID_F] = -1;
	c3d->gfx.player.pos.x = -1;
	c3d->gfx.player.pos.y = -1;
	cub3d_shift_state(c3d, NULL);
}
