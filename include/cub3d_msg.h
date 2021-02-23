#ifndef CUB3D_MSG_H
#define CUB3D_MSG_H

# define PROG_USAGE "./cub3D <map.cub> [--parse-only --save --save-name=]"

/*
** PARSING errors
*/

# define MSG_SPAWN_REDEF "Spawn has been defined more than one time"
/* y index of the mapchar, x index of the mapchar */
# define MSG_NO_WALL "Map: line %ld; col %ld: not surrounded by walls"
# define MSG_SPAWN_MISSING "Spawn location could not be determined"
/* unparsable token */
# define MSG_ID_NOT_PARSED "Token \"%s\" could not be parsed"
# define MSG_ID_EOF "EOF reached, but all the identifiers haven't been parsed"
# define MSG_NO_TOKEN "No suitable token found (NULL token)"
/* identifier, string representation of a number */
# define MSG_NAN "%s: %s: Not a number"
/* identifier, converted string to number */
# define MSG_OVER_RGB "%s: %d: color token greater than 255"
/* identifier, expected argc, actual argc */
# define MSG_BAD_ARG_NB "%s: Expected %d args, found %d"
# define MSG_RES_EQ_ZERO "R: width or height must be > 0, but found zero"
# define MSG_EMPTY_LINE_MAP "Found an empty line in the map definition"
# define MSG_GNL_ERROR "Unexpected error: ft_gnl returned -1"
/* identifier */
# define MSG_PATH_TEX_MISSING "%s: Path to texture missing."
/* identifier */
# define MSG_TEX_REDEFINED "%s: texture already defined."
/* identifier */
# define MSG_TEX_BAD_EXT "%s: a texture file must have a .xpm extension."
/* identifier, token */
# define MSG_UNEXPECTED_TOKEN "%s: unexpected token \"%s\""

/*
** GFX errors
*/

# define MSG_SAVE_BADALLOC "Pixel array alloc failed: overflow detected!"
# define MSG_MLX_IMG_FAILED "Failed to initialize minilibx's image."
# define MSG_MLX_INIT_FAILED "Minilibx initialization failed."
# define MSG_MLX_WIN_FAILED "Minilibx's window initialization failed."
# define MSG_RAY_BADALLOC "Failed to initialize rays."

#endif
