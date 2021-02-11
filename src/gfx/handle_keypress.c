/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 03:15:20 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 03:22:36 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "mlx.h"

#include "cub3d_types.h"

int	handle_keypress(int keysym, t_cub3d *c3d)
{
	if (keysym == XK_Escape)
		mlx_loop_end(c3d->gfx.mlx_ptr);
	return (1);
}
