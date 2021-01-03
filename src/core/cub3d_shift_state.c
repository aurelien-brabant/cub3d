/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_shift_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:40:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/03 23:27:43 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/types.h"

#include "core.h"

bool	cub3d_shift_state(t_cub3d *c3d, bool (*checker)(t_cub3d *))
{
	if (c3d->err[0] == '\0' && !(checker && !checker(c3d)))
	{
		++c3d->state;
		return (true);
	}
	return (false);
}
