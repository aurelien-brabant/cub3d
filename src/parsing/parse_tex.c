/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 13:49:38 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/05 16:09:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/io.h"

#include "core.h"
#include "misc.h"

void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key)
{
	char	*tok;
	char	*next_tok;

	tok = ft_strtok(NULL, " \t");
	if (!tok)
		ft_snprintf(c3d->err, ERR_LEN, "%s: Path to texture missing.", key);
	next_tok = ft_strtok(NULL, " \t");
	if (next_tok)
		ft_snprintf(c3d->err, ERR_LEN,
			"%s: Found unexpected token: \"%s\"", key, next_tok);
	if (c3d->err[0] != '\0')
		return ;
	c3d->dat.tex[id] = tok;
}
