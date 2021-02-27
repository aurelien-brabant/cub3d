/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_gfx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 03:02:57 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 21:32:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "cub3d_types.h"

void	destroy_gfx(t_graphics *gfx)
{
	if (gfx->win_ptr != NULL)
		mlx_destroy_window(gfx->mlx_ptr, gfx->win_ptr);
	if (gfx->mlx_ptr != NULL)
		mlx_destroy_display(gfx->mlx_ptr);
	free(gfx->rays);
	free(gfx->mlx_ptr);
}
