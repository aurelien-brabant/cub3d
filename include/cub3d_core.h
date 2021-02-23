#ifndef CUB3D_CORE_H
# define CUB3D_CORE_H
# include "cub3d_types.h"

void		cub3d_init(t_cub3d *c3d);
void		cub3d_destroy(t_cub3d *c3d);
int			cub3d_shift_state(t_cub3d *c3d, int (*checker)(t_cub3d *));
const char	*cub3d_state_to_str(t_state state);

#endif
