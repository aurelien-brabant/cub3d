/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:27:32 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/23 16:42:58 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "img.h"

void	draw_rect(t_img *img, t_rect rect, int color)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < img->height && i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < img->width && j < rect.x + rect.width)
			img_pix_put(img, j++, i, color);
		++i;
	}
}
