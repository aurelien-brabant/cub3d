/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:38:08 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 00:28:18 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/string.h"
#include "libft/io.h"

#include "parsing.h"

#include "misc.h"

static void	process_token(t_cub3d *c3d, char *tok)
{
	static char	*key[] = { "R", "NO", "EA", "SO", "WE", "S", "F", "C", NULL };
	size_t		i;

	i = 0;
	while (key[i])
	{
		if (ft_strcmp(tok, key[i]) == 0)
		{
			if (i == P_ID_RES)
				parse_res(c3d);
			if (i >= P_ID_NO && i <= P_ID_S)
				parse_tex(c3d, i, key[i]);
			return ;
		}
		++i;
	}
	ft_snprintf(c3d->err, ERR_LEN, "Token \"%s\" could not be parsed.", tok);
}

void	parse_id(t_cub3d *c3d)
{
	char	*ln;
	char	*tok;
	int		ret;

	ret = ft_gnl(c3d->dotcub_fd, &ln);
	ln = gc_put(&c3d->gc, ft_strtrim(gc_put(&c3d->gc, ln), " \t"));
	if (ret <= 0)
		ft_snprintf(c3d->err, ERR_LEN, 
			"EOF reached prematurely. Missing identifiers.");
	if (ln[0] == '\0' || ln[0] == '#')
		return ;
	tok = ft_strtok(ln, " \t");
	if (!tok)
		ft_snprintf(c3d->err, ERR_LEN, "No suitable token found (NULL token)");
	if (c3d->err[0] == '\0')
		process_token(c3d, tok);	
	cub3d_shift_state(c3d, &check_parse_id);
}
