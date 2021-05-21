![abrabant's stats](https://badge42.herokuapp.com/api/stats/abrabant)

# cub3D

cub3D is a bare-bones clone of the
[Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D) game.

This project is part of the 42 school's curriculum: its goal is to introduce
us to graphic programming and the raycasting principle.

# About

## Mandatory part

The mandatory part of this project asks us to recreate a "3D" view of a
maze surrounded by textured walls, with the capability of displaying
sprites.

The player is able to move all around the maze (no collision) by
using the WASD keys (move forward, strafe left, move backward, strafe right).

All the details, such as the color of the floor and the ceiling, wall textures,
resolution, or even the maze itself, are specified in a `.cub` file
which must follow a few rules. You can take a look at the subject or at
the .cub files if you want to know more about that.


## Bonus part

The bonus part allows us to use forbidden functions to add new stuff to our
project. I added several things such as:

- FPS limit and FPS-based movements.
- Shadow effect when a wall is far from the player.
- Wall collision.

# Play

## Dependencies

- gcc
- make
- X11 include files (package xorg)
- XShm extension must be present (package libxext-dev)
- Utility functions from BSD systems - development files (package libbsd-dev)
- clang C compiler

The libft and the minilibx libraries are automatically fetched by the
setup script and compiled by the Makefile.

### Mandatory part

`setup.sh && make re && ./cub3D asset/map/mandatory/VALID_nether.cub`

### Bonus part

`setup.sh && make rebonus && ./cub3D_bonus asset/map/mandatory/VALID_nether.cub`
