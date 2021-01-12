/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parse_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:35:21 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/12 16:41:07 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

#include "libft/io.h"

bool	check_parse_map(t_cub3d *c3d)
{
	ft_snprintf(c3d->err, ERR_LEN, "Map is invalid");
	return (false);
}
