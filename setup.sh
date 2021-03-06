#! /bin/bash

# Use this script if you're coming from github directly and not 42 defense.

MLX_LINUX_GIT=https://github.com/42Paris/minilibx-linux
LIBFT_GIT=https://github.com/aurelien-brabant/libft

[ ! -d "./mlx" ] && git clone $MLX_LINUX_GIT mlx
[ ! -d "./libft" ] && git clone $LIBFT_GIT libft

printf "Setup done.\n"

exit 0
