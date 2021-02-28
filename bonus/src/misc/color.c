/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:23:33 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/28 15:27:43 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A bunch of utility functions used to manipulate colors.
*/

void	change_color_intensity(int *color, float factor)
{
	int	r;
	int	g;
	int	b;

	if (factor > 1)
		factor = 1;
	r = (*color & 0xFF0000) * factor;
	g = (*color & 0xFF00) * factor;
	b = (*color & 0xFF) * factor;
	*color = 0xFF000000 | (r & 0xFF0000) | (g & 0xFF00) | (b & 0xFF);
}

int	make_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
