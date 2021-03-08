/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:38:08 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 21:33:59 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing.h"
#include "msg.h"
#include "libft/cstring.h"
#include "libft/io.h"

static void	process_token(t_cub3d *c3d, char *tok)
{
	static char	*key[] = {"R", "NO", "EA", "SO", "WE", "S", "F", "C", NULL};
	size_t		i;

	i = 0;
	while (key[i])
	{
		if (ft_strcmp(tok, key[i]) == 0)
		{
			if (i == P_ID_RES)
				parse_res(c3d);
			if (i >= P_ID_NO && i <= P_ID_S)
				parse_tex(c3d, (t_parsing_id)i, key[i]);
			if (i >= P_ID_F && i <= P_ID_C)
				parse_col(c3d, (t_parsing_id)i, key[i]);
			return ;
		}
		++i;
	}
	ft_snprintf(c3d->err, ERR_LEN, MSG_ID_NOT_PARSED, tok);
}

void	parse_id(t_cub3d *c3d)
{
	char	*ln;
	char	*tok;
	int		ret;

	ret = ft_gnl(c3d->fildes, &ln);
	ln = ft_vec_add(c3d->gbc, ft_strtrim(ft_vec_add(c3d->gbc, ln), " \t"));
	if (ret <= 0)
		ft_snprintf(c3d->err, ERR_LEN, MSG_ID_EOF);
	if (ln[0] == '\0')
		return ;
	tok = ft_strtok(ln, " \t");
	if (!tok)
		ft_snprintf(c3d->err, ERR_LEN, MSG_NO_TOKEN);
	if (c3d->err[0] == '\0')
		process_token(c3d, tok);
	cub3d_shift_state(c3d, &check_parse_id);
}
