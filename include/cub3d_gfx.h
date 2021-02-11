#ifndef CUB3D_GFX_H
# define CUB3D_GFX_H
# include "cub3d_types.h"

/* Initialize the graphics */

int		init_gfx(t_cub3d *c3d);
void	destroy_gfx(t_graphics *gfx);
int		render(t_cub3d *c3d);

int		handle_keypress(int keysym, t_cub3d *c3d);

#endif
