/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 18:44:54 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/14 18:54:57 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft/io.h"

void	c3d_warn(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "(\033[0;37mWARNING\033[0m) %s\n", msg);
}

void	c3d_info(const char *msg)
{
	ft_dprintf(STDERR_FILENO, "(\033[0;33mINFO\033[0m) %s\n", msg);
}	
