#ifndef CORE_H
# define CORE_H
# include "libft/dvector.h"
# define GARBAGE_COLLECTOR_INIT_COUNT 20
# define ERR_LEN 10000
# define PROG_USAGE "./cub3D <map.cub> [--save]"

typedef enum e_state
{
	ST_NONE = 0,
	ST_STOPPED,
	ST_INITIALIZING,
	ST_PARSING_ARGS,
	ST_PARSING_ID,
	ST_PARSING_MAP,
	ST_RUNNING,
}	t_state;

typedef enum e_metaflag
{
	META_SAVE = 1 << 0,
}	t_metaflag;

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
	uint16_t		col[P_ID_TOTAL - P_ID_F];	
	t_res			res;
}				t_dat;

typedef struct s_cub3d
{
	char			err[ERR_LEN];
	t_state			state;
	t_dvec			gc;
	int				dotcub_fd;
	unsigned char	meta;
	t_dat			dat;

}	t_cub3d;

void	cub3d_init(t_cub3d *c3d);
void	cub3d_destroy(t_cub3d *c3d);
bool	cub3d_shift_state(t_cub3d *c3d, bool (*checker)(t_cub3d *));

#endif
