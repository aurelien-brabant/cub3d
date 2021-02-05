/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:49:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 11:52:04 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/errno.h>

#include "cub3d_core.h"

#include "libft/string.h"
#include "libft/io.h"

static bool	verify_path(char *path, char *err)
{
	int	fd;

	fd = -1;
	if (!ft_strhssfx(path, ".xpm"))
		ft_snprintf(err, ERR_LEN,
			"\"%s\": a texture file must have a .xpm extension.", path);
	else
	{
		fd = open(path, O_RDONLY);
		if (fd == -1 || read(fd, NULL, 0) == -1)
			ft_snprintf(err, ERR_LEN, "%s: %s", path, strerror(errno));
	}
	return (err[0] == '\0');
}

void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key)
{
	char	*tok;
	char	*next_tok;

	if (c3d->mapdat.textures[id - 1] != NULL)
	{
		ft_snprintf(c3d->err, ERR_LEN, "\"%s\" already defined.", key);
		return ;
	}
	tok = ft_strtok(NULL, " \t");
	if (!tok)
		ft_snprintf(c3d->err, ERR_LEN, "\"%s\": Path to texture missing.", key);
	next_tok = ft_strtok(NULL, " \t");
	if (next_tok)
		ft_snprintf(c3d->err, ERR_LEN,
			"%s: Found unexpected token: \"%s\"", key, next_tok);
	if (c3d->err[0] != '\0' || !verify_path(tok, c3d->err))
		return ;
	c3d->mapdat.textures[id - 1] = tok;
}
