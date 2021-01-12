#ifndef CORE_H
# define CORE_H
# include "libft/dvector.h"
# define GARBAGE_COLLECTOR_INIT_COUNT 10
# define MAP_INIT_COUNT 25
# define ERR_LEN 10000
# define PROG_USAGE "./cub3D <map.cub> [--save] [--parseOnly]"

typedef enum e_parsing_state
{
	ST_NONE = 0,
	ST_INITIALIZING,
	ST_PARSING_ARGS,
	ST_PARSING_ID,
	ST_PARSING_MAP,
	ST_STOPPING,
}	t_parsing_state;

typedef enum e_optflag
{
	OPT_SAVE = 0,
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

typedef struct s_res
{
	int	h;
	int	w;
}	t_res;

typedef struct s_dat
{
	char 			*tex[P_ID_S - P_ID_RES];
	int				col[2];	
	t_res			res;
	t_dvec			map;
}				t_dat;

typedef struct s_cub3d
{
	char			err[ERR_LEN];
	t_parsing_state	state;
	t_dvec			gc;
	int				dotcub_fd;
	uint8_t			opt;
	t_dat			dat;

}	t_cub3d;

void	cub3d_init(t_cub3d *c3d);
void	cub3d_destroy(t_cub3d *c3d);
bool	cub3d_shift_state(t_cub3d *c3d, bool (*checker)(t_cub3d *));

#endif
