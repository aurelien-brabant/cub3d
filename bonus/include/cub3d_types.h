/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:55:54 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/27 17:25:15 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cub3d prefix is needed to avoid conflict with the header guard */

#ifndef CUB3D_TYPES_H
# define CUB3D_TYPES_H
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include "libft/vector.h"
# define ERR_LEN 1000
# define CUB3D_ERROR 1
# define CUB3D_SUCCESS 0

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

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_player
{
	t_pos	pos;
	double	rot_angle;
	int8_t	turn_dir;
	int8_t	strafe_dir;
	int8_t	move_dir;
	double	move_speed;
	double	turn_spd;
}	t_player;

typedef struct s_map_data
{
	char		*map_name;
	int			col[2];
	char		*textures[P_ID_S - P_ID_RES];
	int			win_width;
	int			win_height;
	t_vector	map;
}	t_map_data;

typedef struct s_img
{
	int		bpp;
	int		endian;
	int		line_len;
	char	*addr;
	void	*mlx_img;
	int		height;
	int		width;
}	t_img;

typedef struct s_ray
{
	int				id;
	double			angle;
	bool			was_hit_vert;
	t_pos			horz_hit;
	t_pos			vert_hit;
	t_pos			hit;
	double			dist;
	t_img			*tex_img;
}	t_ray;

typedef struct s_sprite
{
	t_pos	pos;
	double	distance;
	double	dpheight;
	double	dpwidth;
	int		dpx_start;
	int		dpx_end;
	int		dpy_start;
	int		dpy_end;
	double	angle;
}	t_sprite;

typedef struct s_graphics
{
	void			*mlx_ptr;
	void			*win_ptr;
	int64_t			init_time;
	int16_t			frame_time;
	int64_t			last_frame_ticks;
	int64_t			last_sec_ticks;
	int8_t			fps;
	double			delta_time;
	double			fov;
	double			dist_proj_plane;
	int				num_rays;
	int				win_height;
	int				win_width;
	t_img			dpimg;
	t_img			teximg[5];
	t_vector		sprites;
	t_vector		visible_sprites;
	t_ray			*rays;
	t_player		player;
}	t_graphics;

typedef struct s_cub3d
{
	t_state		state;
	char		err[ERR_LEN];
	char		*screenshot_name;
	int			fildes;
	uint8_t		opt;
	t_map_data	mapdat;
	t_graphics	gfx;
	t_vector	gbc;
}	t_cub3d;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
}	t_rect;

#endif /* CUB3D_TYPES_H  */
