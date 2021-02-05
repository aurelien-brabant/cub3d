#ifndef CUB3D_MSG_H
#define CUB3D_MSG_H

# define PROG_USAGE "Usage: ./cub3D <map.cub> [--parseOnly]"

/*
** parsing errors
*/

# define MSG_SPAWN_REDEF "Spawn has been defined more than one time"
# define MSG_NO_WALL "Map: line %ld; col %ld: not surrounded by walls"
# define MSG_SPAWN_MISSING "Spawn location could not be determined"
# define MSG_ID_NOT_PARSED "Token \"%s\" could not be parsed"
# define MSG_ID_EOF "EOF reached, but all the identifiers haven't been parsed"
# define MSG_NO_TOKEN "No suitable token found (NULL token)"
# define MSG_NAN "%s: %s: Not a number"
# define MSG_OVER_RGB "%s: %d: color token greater than 255"
# define MSG_BAD_ARG_NB "%s: Expected %d args, found %d"
# define MSG_RES_EQ_ZERO "R: width or height must be > 0, but found zero"
# define MSG_EMPTY_LINE_MAP "Found an empty line in the map definition"
# define MSG_GNL_ERROR "Unexpected error: ft_gnl returned -1"

#endif
