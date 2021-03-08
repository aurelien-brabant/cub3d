/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:49:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 21:34:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/errno.h>

#include "cub3d.h"
#include "msg.h"
#include "libft/cstring.h"
#include "libft/io.h"

static uint8_t	verify_path(char *path, char *err)
{
	int	fd;

	fd = -1;
	if (!ft_strhssfx(path, ".xpm"))
		return (!ft_snprintf(err, ERR_LEN, MSG_TEX_BAD_EXT, path));
	fd = open(path, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		return (!ft_snprintf(err, ERR_LEN, "%s: %s", path, strerror(errno)));
	return (1);
}

void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key)
{
	char	*tok;
	char	*next_tok;

	if (c3d->mapdat.textures[id - 1] != NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, MSG_TEX_REDEFINED, key);
		return ;
	}
	tok = ft_strtok(NULL, " \t");
	if (tok == NULL)
		ft_snprintf(c3d->err, ERR_LEN, MSG_PATH_TEX_MISSING, key);
	next_tok = ft_strtok(NULL, " \t");
	if (next_tok != NULL)
		ft_snprintf(c3d->err, ERR_LEN, MSG_UNEXPECTED_TOKEN, key, next_tok);
	if (c3d->err[0] != '\0' || !verify_path(tok, c3d->err))
		return ;
	c3d->mapdat.textures[id - 1] = tok;
}
