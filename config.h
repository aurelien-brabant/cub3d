#ifndef CONFIG_H
# define CONFIG_H
# include <X11/keysym.h>

/*
** cub3D USER CONFIGURATION
**
** Anything put in this header is intended to be modified
** modified by the user.
**
** DON'T FORGET to run 'make reconfig' when changes have been made.
*/

/*
** The field of view of the player
** 60 is the default, it is probably the most realistic (mimics human FOV).
*/

# define FOV_ANGLE 90

/*
** How many pixel columns a ray will be responsible for. Providing important
** values will likely improve the FPS a lot, but the final result will
** be more pixelized too.
*/

# define RAY_THICKNESS 1

/* KEY BINDINGS */

# define KB_QUIT			XK_Escape
# define KB_MOVE_FORWARD	XK_w
# define KB_MOVE_BACKWARD	XK_s
# define KB_MOVE_LEFT		XK_a
# define KB_MOVE_RIGHT		XK_d
# define KB_TURN_LEFT		XK_Left
# define KB_TURN_RIGHT		XK_Right

#endif
