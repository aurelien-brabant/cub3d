#ifndef CUB3D_TYPES_H
# define CUB3D_TYPES_H
# include <stdint.h>
# include <stdbool.h>
# include "libft/vector.h"
# define ERR_LEN 1000

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

typedef struct s_cub3d
{
	t_state		state;
	char		err[ERR_LEN];
	uint8_t		opt;
	int			fildes;
	t_map_data	mapdat;
	t_game_data	gamedat;
	t_vector	gbc;
}	t_cub3d;

#endif
