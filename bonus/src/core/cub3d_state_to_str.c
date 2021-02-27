/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_state_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:13:49 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 14:19:21 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_types.h"

const char	*cub3d_state_to_str(t_state state)
{
	static const char	*strs[] = {
		"ST_NONE",
		"ST_INITIALIZING",
		"ST_PARSING_ARGS",
		"ST_PARSING_ID",
		"ST_PARSING_MAP",
		"ST_INGAME",
		"ST_STOPPING",
	};

	return (strs[state]);
}
