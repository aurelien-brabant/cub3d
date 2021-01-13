/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:35:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/13 21:08:08 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft/io.h"
#include "libft/dvector.h"

#include "core.h"
#include "msg.h"

/*
** A simple wrapper around the standard free function, to use it
** with my vector implementation.
**
** @param	the address of a pointer to an element, element which is to
** be freed.
*/

static void	wrap_free(void **el)
{
	free(*el);
	*el = NULL;
}

/*
** Get more information about where the error occured. 
**
** @param	state	=> the state
**
** @return an immutable string describing at which step the error occured.
*/

static const char	*get_state_info(unsigned char state)
{
	if (state == ST_INITIALIZING)
		return (MSG_INIT_CTXT);
	if (state == ST_PARSING_ARGS)
		return (MSG_P_ARG_CTXT);
	if (state == ST_PARSING_ID)
		return (MSG_P_ID_CTXT);
	if (state == ST_PARSING_MAP)
		return (MSG_P_MAP_CTXT);
	return (MSG_UNKNOWN_CTXT);
}

void	clear_gnl(int fd)
{
	char	*line;

	line = NULL;
	while (ft_gnl(fd, &line) > 0)
		free(line);
	free(line);
}

void	cub3d_destroy(t_cub3d *c3d)
{
	if (c3d->gc.val)
		ft_dvec_destroy(&c3d->gc, &wrap_free);
	if (c3d->dat.map.val)
		ft_dvec_destroy(&c3d->dat.map, NULL);
	if (c3d->state != ST_STOPPING)
	{
		ft_dprintf(STDERR_FILENO, MSG_ERR_FMT,
			get_state_info(c3d->state), c3d->err);
		if (c3d->state > ST_PARSING_ARGS)
			clear_gnl(c3d->dotcub_fd);
		if (c3d->dotcub_fd != -1)
			close(c3d->dotcub_fd);
		exit(1);
	}
	exit(0);
}
