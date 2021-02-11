# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 22:55:32 by abrabant          #+#    #+#              #
#    Updated: 2021/02/11 23:21:27 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------[= PROJECT   =]--------------- #

TARGET			= cub3D
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -Wpedantic
INC_DIR			= -I$(LIBFT_PATH)/include -I$(MLX_PATH) -Iinclude -I.
LIB_DIR			= -L$(MLX_PATH) -L$(LIBFT_PATH)
RM				= rm -rf

# ---------------[=  DEPS                      =]--------------- #

# MinilibX (linux version)
MLX_PATH		= mlx
MLX_ARCHIVE		= $(MLX_PATH)/libmlx.a
MLX_LINK		= -lmlx -lX11 -lXext

# Libft
LIBFT_PATH		= libft
LIBFT_ARCHIVE	= $(LIBFT_PATH)/libft.a
LIBFT_LINK		= -lft

# ---------------[=    SOURCE CODE FILES      =]--------------- #

SRC_DIR			= ./src
SRC_VPATH		= $(SRC_DIR) $(SRC_DIR)/core $(SRC_DIR)/parsing:		\
				$(SRC_DIR)/misc:$(SRC_DIR)/gfx

CORE			= cub3d_init.c cub3d_destroy.c cub3d_shift_state.c		\
				cub3d_state_to_str.c

PARSING			= parse_id.c parse_tex.c check_parse_id.c parse_res.c	\
				parse_col.c parse_map.c check_parse_map.c

MISC			= gc.c parsing_utils.c color.c map.c

GFX				= init_gfx.c destroy_gfx.c handle_keypress.c			\
				render.c img_pix_put.c draw_rect.c render_minimap.c		\
				render_player.c handle_mouse.c

SRCS		 	= main.c $(GFX) $(CORE) $(PARSING) $(MISC)

# ---------------[=     SOURCES - GENERAL     =]--------------- #

VPATH			= $(SRC_VPATH) 
OBJ_DIR			= ./.obj
OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)


# ---------------[=  RULES    =]--------------- #

# Generic rules

all: $(TARGET)

test:
	./test.sh

clean:
	$(RM) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE) $(OBJS) $(OBJ_DIR)
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(TARGET)
	$(RM) $(LIBFT_ARCHIVE)
	$(RM) $(MLX_ARCHIVE)

re: fclean all

reload:
	$(RM) $(TARGET)
	$(RM) $(OBJS) $(OBJ_DIR)
	make all
	

.PHONY: all clean fclean re test

# Build rules

$(TARGET): $(MLX_ARCHIVE) $(LIBFT_ARCHIVE) $(OBJ_DIR) $(OBJS) 
	$(CC) $(OBJS) $(LIB_DIR) $(LIBFT_LINK) $(MLX_LINK) -lm -o $(TARGET) 

# Make libft archive
$(LIBFT_ARCHIVE):
	make -C $(LIBFT_PATH)

# Make mlx archive
$(MLX_ARCHIVE):
	make -C $(MLX_PATH)

# Create OBJ_DIR if doesn't exist
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# Compilation of each c file
$(OBJ_DIR)/%.o:%.c
	$(CC) $(CFLAGS) $(INC_DIR) -g -c $< -o $@
