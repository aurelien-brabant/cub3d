#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H
# include "cub3d_types.h"

void	parse_id(t_cub3d *c3d);
void	parse_tex(t_cub3d *c3d, t_parsing_id id, char *key);
void	parse_res(t_cub3d *c3d);
void	parse_col(t_cub3d *c3d, int id, char *key);
void	parse_map(t_cub3d *c3d);
int		check_parse_id(t_cub3d *c3d);
int		check_parse_map(t_cub3d *c3d);

#endif
