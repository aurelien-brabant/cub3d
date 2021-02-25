/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:46:32 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/24 23:55:55 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "raycasting.h"

uint8_t	is_ray_facing_left(t_ray *ray)
{
	return (ray->angle > M_PI / 2 && ray->angle < M_PI * 1.5);
}

uint8_t	is_ray_facing_right(t_ray *ray)
{
	return (ray->angle > M_PI * 1.5 || ray->angle < M_PI_2);
}

uint8_t	is_ray_facing_top(t_ray *ray)
{
	return (ray->angle > M_PI && ray->angle < M_PI * 2);
}

uint8_t	is_ray_facing_bot(t_ray *ray)
{
	return (ray->angle > 0 && ray->angle < M_PI);
}
