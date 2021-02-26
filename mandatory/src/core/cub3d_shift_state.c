/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_shift_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:40:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 18:12:06 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/io.h"

void	cub3d_shift_state(t_cub3d *c3d, bool (*checker)(t_cub3d *))
{
	if (c3d->err[0] == '\0' && !(checker && !checker(c3d)))
	{
		ft_printf("\033[1;36m%s\033[0m\t\t\t[\033[0;32mOK\033[0m]\n",
			cub3d_state_to_str(c3d->state));
		++c3d->state;
	}
}
