/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:12:37 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 19:19:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "cub3d_types.h"

int64_t	c3d_get_time_now(void)
{
	struct timespec	tspec;

	timespec_get(&tspec, TIME_UTC);
	return (tspec.tv_sec * 1000 + tspec.tv_nsec / 1000000);
}

int64_t	c3d_get_ticks(t_graphics *gfx)
{
	return (c3d_get_time_now() - gfx->init_time);
}
