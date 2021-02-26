/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:46:32 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/26 18:03:33 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raycasting.h"

bool	is_ray_facing_left(t_ray *ray)
{
	return (ray->angle > M_PI / 2 && ray->angle < M_PI * 1.5);
}

bool	is_ray_facing_right(t_ray *ray)
{
	return (ray->angle > M_PI * 1.5 || ray->angle < M_PI_2);
}

bool	is_ray_facing_top(t_ray *ray)
{
	return (ray->angle > M_PI && ray->angle < M_PI * 2);
}

bool	is_ray_facing_bot(t_ray *ray)
{
	return (ray->angle > 0 && ray->angle < M_PI);
}
