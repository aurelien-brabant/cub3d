#include <math.h>

#include "img.h"

static int	abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void	draw_line(t_img *img, t_line line, int color)
{
	t_coords	delta;
	t_pos		step;
	t_pos		cur;
	int			steps;
	int			i;

	delta.x = line.x2 - line.x1;
	delta.y = line.y2 - line.y1;
	if (abs(delta.x) > abs(delta.y))
		steps = abs(delta.x);
	else
		steps = abs(delta.y);
	step.x = delta.x / (double)steps;
	step.y = delta.y / (double)steps;
	i = 0;
	cur.x = line.x1;
	cur.y = line.y1;
	while (i <= steps && cur.x < img->width && cur.y < img->height)
	{
		img_pix_put(img, round(cur.x), round(cur.y), color);
		cur.x += step.x;
		cur.y += step.y;
		++i;
	}
}
