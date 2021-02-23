/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:45:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 00:56:50 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	deg2rad(double deg)
{
	return (deg * (M_PI / 180));
}

double	rad2deg(double rad)
{
	return (rad * (180 / M_PI));
}

/*
** Ensure the angle is between 0 and 2 PI radians.
*/

double	normalize_angle(double angle)
{
	if (angle > M_PI * 2)
		angle = fmod(angle, M_PI * 2);
	if (angle < 0)
		angle = M_PI * 2 - fmod(-angle, M_PI * 2);
	return (angle);
}
