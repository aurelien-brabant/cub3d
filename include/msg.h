#ifndef MSG_H
# define MSG_H

/*
** All the hardcoded program messages
*/

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

/*
** error context
*/

# define MSG_INIT_CTXT "The error occured during initialization"
# define MSG_P_ARG_CTXT "The error occured while parsing the command line args"
# define MSG_P_ID_CTXT "The error occured during the parsing of identifiers"
# define MSG_P_MAP_CTXT "The error occured during the parsing of the map"
# define MSG_UNKNOWN_CTXT "Error context could not be determined"

/*
** error  display
*/

# define MSG_ERR_FMT "\033[1;31mError\033[0;31m\n%s:\n%s\n\033[0m"

#endif
