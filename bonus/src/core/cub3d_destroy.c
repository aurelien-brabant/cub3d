/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 16:35:19 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 18:10:49 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "cub3d.h"
#include "msg.h"
#include "img.h"
#include "gfx.h"
#include "libft/io.h"
#include "libft/vector.h"

/* Ensure that all the lines have been read to free the linked list node */

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
		"\033[1;36m%s\t\t\033[0m[\033[0;31mKO\033[0m]\033[0m\nError\n%s\n",
			cub3d_state_to_str(c3d->state), c3d->err);
	if (c3d->state >= ST_PARSING_ID)
		clear_gnl(c3d->fildes);
	if (c3d->state >= ST_INGAME)
	{
		destroy_img(c3d);
		destroy_gfx(&c3d->gfx);
	}
	if (c3d->fildes != -1)
		close(c3d->fildes);
	exit(c3d->err[0] != '\0');
}
