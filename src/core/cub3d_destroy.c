/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:35:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 17:44:23 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "cub3d_core.h"
#include "cub3d_types.h"
#include "cub3d_msg.h"

#include "libft/io.h"
#include "libft/vector.h"

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
	if (c3d->gbc != NULL)
		ft_vec_destroy(c3d->gbc, &free);
	if (c3d->mapdat.map != NULL)
		ft_vec_destroy(c3d->mapdat.map, NULL);
	if (c3d->err[0] != '\0')
		ft_dprintf(STDERR_FILENO,
		"\033[1;36m%s\t\t\033[0m[\033[0;31mKO\033[0m]\033[0m\n%s\n",
			cub3d_state_to_str(c3d->state), c3d->err);
	if (c3d->state > ST_PARSING_ARGS)
		clear_gnl(c3d->fildes);
	if (c3d->fildes != -1)
		close(c3d->fildes);
	exit(0);
}
