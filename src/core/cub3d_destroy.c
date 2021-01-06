/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:35:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 15:44:37 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft/io.h"
#include "libft/dvector.h"

#include "core.h"

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
		return ("The error occured during initialization");
	if (state == ST_PARSING_ARGS)
		return ("The error occured while parsing the command line args");
	if (state == ST_PARSING_ID)
		return ("The error occured during the parsing of identifiers");
	if (state == ST_PARSING_MAP)
		return ("The error occured during the parsing of the map");
	if (state == ST_RUNNING)
		return ("The error occured while running the program");
	return ("Unexpected error. That's not normal.");
}

void	clear_gnl(int fd)
{
	char	*line;

	line = NULL;
	while (ft_gnl(fd, &line) > 0)
		free(line);
	free(line);
}

/*
** Print the error on stderr, if any.
**
** @param	state	=> the state
**
*/

static void	print_error(unsigned char state, char *err)
{
	const char	*state_info;

	state_info = get_state_info(state);
	if (err[0])
		ft_dprintf(STDERR_FILENO, "\033[0;31mError\n\033[0m%s:\n%s\n",
			state_info, err);
	else
		ft_dprintf(STDERR_FILENO, "\033[0;31mError\n\033[0m%s:\n%s\n",
			state_info, 
			"Unexpected error - program exited sooner than expected.");

}

void	cub3d_destroy(t_cub3d *c3d)
{
	if (c3d->gc.val)
		ft_dvec_destroy(&c3d->gc, &wrap_free);
	if (c3d->state != ST_STOPPED)
	{
		print_error(c3d->state, c3d->err);
		if (c3d->state > ST_PARSING_ARGS)
			clear_gnl(c3d->dotcub_fd);
		if (c3d->dotcub_fd != -1)
			close(c3d->dotcub_fd);
		exit(1);
	}
	exit(0);
}
