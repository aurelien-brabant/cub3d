#ifndef CUB3D_GFX_H
# define CUB3D_GFX_H
# include "cub3d_types.h"

/*
** Initialize the graphics using the minilibx API
**
** @param c3d:
** A pointer to the cub3d object. Contains all the program's data.
**
** @return:
** 1 if initiliazation went well, 0 if an error occured. The value
** of c3d->err is set to describe the error.
*/

int		init_gfx(t_cub3d *c3d);

/*
** Destroy the graphics initialized by the minilibx. 
**
** @param gfx:
** A pointer to the t_graphics object. Holds all the variables
** needed to make the graphics work.
*/

void	destroy_gfx(t_graphics *gfx);

/*
** Rendering function called at each loop frame, used 
** to render the elements on the window.
**
** @param c3d:
** A pointer to the cub3d object. Contains all the program's data.
**
** @return:
** Required to comply to the minilibx API, but it is not used.
*/

int		render(t_cub3d *c3d);

/*
** Handle the keypress X event through the minilibx API.
**
** @param keysym:
** The key symbol correspond to the key which has been pressed
** (complete list available in X11/keysym.h)
**
** @param c3d:
** A pointer to the cub3d object. Contains all the program's data.
**
** @return:
** Required to comply to the minilibx API, but it is not used.
*/

void	render_minimap(t_vector map, t_img *img);

void	render_player(t_img *img, t_player *player);

int		handle_keypress(int keysym, t_cub3d *c3d);
int		handle_keyrelease(int keysym, t_cub3d *c3d);

int		handle_mouse(int button, int x, int y, t_cub3d *c3d);

/*
** Put a pixel directly on an image object. 
**
** @param img:
** A pointer to an t_img object, corresponding to the image
** the pixel needs to be put on.
**
** @param x:
** Position of the pixel on the x axis.
**
** @param y:
** Position of the pixel on the y axis.
**
** @param color:
** A true color compliant value which indicates
** the pixel's color.
*/

void	img_pix_put(t_img *img, int x, int y, int color);

/*
** Draw a rectangle of pixels on the given image.
**
** @param img:
** A pointer to an t_img object, corresponding to the image
** the pixel needs to be put on.
**
** @param rect:
** A t_rect object that specifies the coordinates of the top left corner of
** the rectangle (x, y) as well as its width and height.
**
** @param color;
** A true color compliant value which indicates
** the pixel's color.
*/

void	draw_rect(t_img *img, t_rect rect, int color);
void	draw_line(t_img *img, t_line line, int color);
void	draw_circle(t_img *img, int x, int y, int radius);

void	cast_rays(t_graphics *gfx, t_player *player, t_map_data *mapdat);
void	render_rays(t_player *player, t_graphics *gfx);

double	get_horz_distance(t_ray *ray, t_player *player, t_map_data *mapdat);
double	get_vert_distance(t_ray *ray, t_player *player, t_map_data *mapdat);

void	update(t_cub3d *c3d);


#endif
