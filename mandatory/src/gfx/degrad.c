/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 21:45:39 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/24 21:39:52 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float	deg2rad(float deg)
{
	return (deg * (M_PI / 180));
}

float	rad2deg(float rad)
{
	return (rad * (180 / M_PI));
}

/*
** Ensure the angle is between 0 and 2 PI radians.
*/

float	normalize_angle(float angle)
{
	angle = remainder(angle, M_PI * 2.0);
	if (angle < 0)
		angle = M_PI * 2.0 + angle;
	return (angle);
}
