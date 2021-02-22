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

# define FOV_ANGLE 90

/* KEY BINDINGS */

# define KB_QUIT			0xff1b
# define KB_TURN_LEFT		0xff51
# define KB_TURN_RIGHT		0xff53

/*
# define KB_MOVE_FORWARD	0x007a
# define KB_MOVE_BACKWARD	0x0073
# define KB_MOVE_LEFT		0x0071
# define KB_MOVE_RIGHT		0x0064
*/

# define KB_MOVE_FORWARD	0x0077
# define KB_MOVE_BACKWARD	0x0073
# define KB_MOVE_LEFT		0x0061
# define KB_MOVE_RIGHT		0x0064

#endif
