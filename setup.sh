#! /bin/bash

MLX_LINUX_GIT=https://github.com/42Paris/minilibx-linux
LIBFT_GIT=https://github.com/aurelien-brabant/libft

[ ! -d "./mlx" ] && git clone $MLX_LINUX_GIT mlx
[ ! -d "./libft" ] && git clone $LIBFT_GIT libft

exit 0
