/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 22:07:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/11 22:11:01 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <cub3d_gfx.h>

int	handle_mouse(int button, int x, int y, t_cub3d *c3d)
{
	(void)button;
	(void)c3d;
	printf("[CLICK] x: %d ; y: %d\n", x, y);
	return (0);
}
