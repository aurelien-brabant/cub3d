/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:23:33 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/06 14:50:57 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A bunch of utility functions used to manipulate colors.
*/

int	make_rgb(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}
