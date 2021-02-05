/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:12:45 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 11:56:53 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/string.h"
#include "libft/ctype.h"

/*
** Checks if a stringified number should be parsed.
** A number is parsable if:
** - It has only numeric digits - no other character allowed, even sign.
** Blanks/Tabs may be found at the start/end of the string as they are
** going to be trimmed.
*/

int	is_parsable_nb(char *nb_str)
{
	const char	*trimmed;
	size_t		i;
	bool		ret;

	i = 0;
	ret = 1;
	trimmed = ft_strtrim(nb_str, " ");
	while (trimmed[i])
	{
		if (!ft_isdigit(trimmed[i++]))
		{
			ret = 0;
			break ;
		}
	}
	free((void *)trimmed);
	return (ret);
}
