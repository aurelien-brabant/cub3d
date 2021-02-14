#ifndef CUB3D_TYPES_H
# define CUB3D_TYPES_H
# include <stdint.h>
# include <stdbool.h>
# include <stddef.h>
# include "libft/vector.h"
# define ERR_LEN 1000
# define TILE_SIZE 50
# define MINIMAP_FACTOR 0.3

typedef enum e_state
{
	ST_NONE = 0,
	ST_INITIALIZING,
	ST_PARSING_ARGS,
	ST_PARSING_ID,
	ST_PARSING_MAP,
	ST_INGAME,
	ST_STOPPING,
}	t_state;

/*
** Option flags
*/

typedef enum e_optflag
{
	OPT_SAVE = 1,
	OPT_PARSE_ONLY,
	OPT_TOTAL,
}	t_optflag;

typedef enum e_parsing_id
{
	P_ID_RES = 0,
	P_ID_NO,
	P_ID_EA,
	P_ID_SO,
	P_ID_WE,
	P_ID_S,
	P_ID_F,
	P_ID_C,
	P_ID_TOTAL,
}	t_parsing_id;

typedef struct s_player
{
	double	x;
	double	y;
	double	rot_angle;
	int		turn_dir; /* 1 for right, -1 for left */
	int		move_dir;
	int		move_speed;
	double	turn_spd;
}	t_player;

typedef struct s_map_data
{
	int			col[2];
	char 		*textures[P_ID_S - P_ID_RES];
	long long	win_width;
	long long	win_height;
	t_vector	map;
}	t_map_data;

typedef struct s_game_data
{
	t_player	player;
}	t_game_data;

typedef struct s_img
{
	int 	bpp;
	int 	endian;
	int		line_len;
	char	*addr;
	void	*mlx_img;
	int		height;
	int		width;
}	t_img;

typedef struct	s_ray
{
	double	angle;
	int		facing_down;
	int		facing_left;
	int 	hit_vert;
	double	horz_wall_hit[2];
	double	vert_wall_hit[2];
	double	wall_hit[2];
	double	wall_dist;
}	t_ray;

typedef struct s_graphics
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	dpimg[2];
	t_ray	*rays;
	int		num_rays;
	double	fov;
}	t_graphics;

typedef struct s_cub3d
{
	t_state		state;
	char		err[ERR_LEN];
	uint8_t		opt;
	int			fildes;
	t_map_data	mapdat;
	t_game_data	gamedat;
	t_graphics	gfx;
	t_vector	gbc;
}	t_cub3d;

/* GRAPHICS */

typedef struct	s_rect
{
	int x;
	int y;
	int width;
	int height;
	int border_size;
	int border_color;
}				t_rect;

typedef struct	s_line
{
	int x1;
	int y1;
	int x2;
	int y2;
}				t_line;

#endif
