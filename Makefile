# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 22:55:32 by abrabant          #+#    #+#              #
#    Updated: 2021/02/23 02:08:42 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------[= PROJECT   =]--------------- #

TARGET			= cub3D
TARGET_BONUS	= cub3D_bonus
CC				= clang
CFLAGS			= -Wall -Wextra -Werror -Wpedantic -O3
INC_DIR			= -I$(LIBFT_PATH)/include -I$(MLX_PATH) -Imandatory/include -Imandatory
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

# ----- MANDATORY PART ----- #

CORE			= cub3d_init.c cub3d_destroy.c cub3d_shift_state.c		\
				cub3d_state_to_str.c

PARSING			= parse_id.c parse_tex.c check_parse_id.c parse_res.c	\
				parse_col.c parse_map.c check_parse_map.c

MISC			= gc.c parsing_utils.c color.c map.c degrad.c			\
				output.c

GFX				= init_gfx.c destroy_gfx.c handle_keypress.c			\
				render.c img_pix_put.c draw_rect.c 						\
				handle_mouse.c update.c									\
				handle_keyrelease.c raycast.c							\
				raycast_horizontal.c raycast_vertical.c					\
				get_points_dist.c render_walls.c init_img.c				\
				img_pix_get.c sprite.c init_sprite.c sprite_2.c			\
				render_aim.c render_save_bmp.c handle_destroy.c

BMP				= bmp_new.c bmp_encode_file.c bmp_int_rev_buf.c

SRCS		 	= mandatory/src/main.c											\
				$(addprefix mandatory/src/gfx/, $(GFX))					\
				$(addprefix mandatory/src/core/, $(CORE))				\
				$(addprefix mandatory/src/parsing/, $(PARSING))			\
				$(addprefix mandatory/src/misc/, $(MISC))				\
				$(addprefix mandatory/src/bmp/, $(BMP))

# ---------------[=     SOURCES - GENERAL     =]--------------- #

OBJ_DIR			= ./.obj
OBJS			= $(SRCS:%.c=%.o)


# ---------------[=  RULES    =]--------------- #

# Generic rules

all: $(TARGET)

test:
	./test.sh

clean:
	$(RM) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE) $(OBJS) $(OBJ_DIR)
	make clean -C $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(TARGET)
	$(RM) $(LIBFT_ARCHIVE)
	$(RM) $(MLX_ARCHIVE)

re: fclean all

editconfig:
	$(EDITOR) config.h
	make reconfig

reconfig:
	$(RM) $(TARGET)
	$(RM) $(OBJS) $(OBJ_DIR)
	make all
	

.PHONY: all clean fclean re test

# Build rules

$(TARGET): $(OBJ_DIR) $(MLX_ARCHIVE) $(LIBFT_ARCHIVE) $(OBJS)
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
%.o:%.c
	$(CC) $(CFLAGS) $(INC_DIR) -g -c $< -o $@
