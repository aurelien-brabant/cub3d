# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 22:55:32 by abrabant          #+#    #+#              #
#    Updated: 2021/02/27 00:49:59 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------[= PROJECT   =]--------------- #

TARGET			= cub3D
TARGET_BONUS	= cub3D_bonus
CC				= clang
CFLAGS			= -Wall -Wextra -Werror
CFLAGS_BONUS	= -Wall -Wextra -Werror -O3
INC_DIR			= -I$(LIBFT_PATH)/include -I$(MLX_PATH) -Imandatory/include -Imandatory
INC_DIR_BONUS	= -I$(LIBFT_PATH)/include -I$(MLX_PATH) -Ibonus/include -Ibonus
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

MISC			= parsing_utils.c color.c map.c output.c

GFX				= init_gfx.c destroy_gfx.c get_points_dist.c degrad.c

RAYCASTING		= raycast_horizontal.c raycast_vertical.c raycast.c		\
				draw_walls.c draw_aim.c render.c						\
				update.c init_sprite.c draw_sprite2.c					\
				draw_sprite.c init_raycasting.c ray_orientation.c

IMG				= init_img.c img_pix_get.c img_pix_put.c draw_rect.c

EVENTS			= install_event_handlers.c handle_keyrelease.c			\
				handle_keypress.c

BMP				= bmp_new.c bmp_encode_file.c bmp_int_rev_buf.c			\
				render_save_bmp.c

SRCS		 	= mandatory/src/main.c									\
				$(addprefix mandatory/src/gfx/, $(GFX))					\
				$(addprefix mandatory/src/core/, $(CORE))				\
				$(addprefix mandatory/src/parsing/, $(PARSING))			\
				$(addprefix mandatory/src/misc/, $(MISC))				\
				$(addprefix mandatory/src/bmp/, $(BMP))					\
				$(addprefix mandatory/src/events/, $(EVENTS))			\
				$(addprefix mandatory/src/img/, $(IMG))					\
				$(addprefix mandatory/src/raycasting/, $(RAYCASTING))

# ----- BONUS PART ----- #

CORE_BONUS				= cub3d_init.c cub3d_destroy.c cub3d_shift_state.c		\
						cub3d_state_to_str.c

PARSING_BONUS			= parse_id.c parse_tex.c check_parse_id.c parse_res.c	\
						parse_col.c parse_map.c check_parse_map.c

MISC_BONUS				= parsing_utils.c color.c map.c output.c

GFX_BONUS				= init_gfx.c destroy_gfx.c get_points_dist.c degrad.c

RAYCASTING_BONUS		= raycast_horizontal.c raycast_vertical.c raycast.c		\
						draw_walls.c draw_aim.c render.c						\
						update.c init_sprite.c draw_sprite2.c					\
						draw_sprite.c init_raycasting.c ray_orientation.c

IMG_BONUS				= init_img.c img_pix_get.c img_pix_put.c draw_rect.c

EVENTS_BONUS			= install_event_handlers.c handle_keyrelease.c			\
						handle_keypress.c

BMP_BONUS				= bmp_new.c bmp_encode_file.c bmp_int_rev_buf.c			\
						render_save_bmp.c

SRCS_BONUS		 		= bonus/src/main.c									\
						$(addprefix bonus/src/gfx/, $(GFX_BONUS))			\
						$(addprefix bonus/src/core/, $(CORE_BONUS))			\
						$(addprefix bonus/src/parsing/, $(PARSING_BONUS))	\
						$(addprefix bonus/src/misc/, $(MISC_BONUS))			\
						$(addprefix bonus/src/bmp/, $(BMP_BONUS))			\
						$(addprefix bonus/src/events/, $(EVENTS_BONUS))		\
						$(addprefix bonus/src/img/, $(IMG_BONUS))			\
						$(addprefix bonus/src/raycasting/, $(RAYCASTING_BONUS))

# ---------------[=     SOURCES - GENERAL     =]--------------- #

OBJ_DIR			= ./.obj
OBJS			= $(SRCS:%.c=%.o)
OBJS_BONUS		= $(SRCS_BONUS:%.c=%.o)


# ---------------[=  RULES    =]--------------- #

# Generic rules

all: $(TARGET)

bonus: $(TARGET_BONUS)

test:
	./test.sh

clean:
	$(RM) $(OBJS)
	make clean -C $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)

cleanbonus:
	$(RM) $(OBJS_BONUS)
	make clean -C $(MLX_PATH)
	make fclean -C $(LIBFT_PATH)

cleanfull: clean cleanbonus

fclean: clean
	$(RM) $(TARGET)
	$(RM) $(LIBFT_ARCHIVE)
	$(RM) $(MLX_ARCHIVE)

fcleanbonus: cleanbonus
	$(RM) $(TARGET_BONUS)
	$(RM) $(LIBFT_ARCHIVE)
	$(RM) $(MLX_ARCHIVE)

fcleanfull: fclean fcleanbonus

re: fclean $(TARGET)

rebonus: fcleanbonus $(TARGET_BONUS)

.PHONY: all clean fclean re test

# Build rules

$(TARGET): $(OBJ_DIR) $(MLX_ARCHIVE) $(LIBFT_ARCHIVE) $(OBJS)
	$(CC) $(OBJS) $(LIB_DIR) $(LIBFT_LINK) $(MLX_LINK) -lm -o $(TARGET)

$(TARGET_BONUS): $(OBJ_DIR) $(MLX_ARCHIVE) $(LIBFT_ARCHIVE) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIB_DIR) $(LIBFT_LINK) $(MLX_LINK) -lm -o $(TARGET_BONUS)

# Make libft archive
$(LIBFT_ARCHIVE):
	make -C $(LIBFT_PATH)

# Make mlx archive
$(MLX_ARCHIVE):
	make -C $(MLX_PATH)

# MANDATORY PART COMPILATION
mandatory/src/%.o:mandatory/src/%.c
	$(CC) $(CFLAGS) $(INC_DIR) -g -c $< -o $@

# BONUS PART COMPILATION
bonus/src/%.o:bonus/src/%.c
	$(CC) $(CFLAGS_BONUS) $(INC_DIR_BONUS) -g -c $< -o $@
