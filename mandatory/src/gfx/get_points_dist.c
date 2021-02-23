/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points_dist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:03:01 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/18 02:04:13 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	get_points_dist(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) *(x2 - x1) + (y2 - y1) * (y2 - y1)));
}
