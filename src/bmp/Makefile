# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurelienbrabant <marvin@42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 10:35:01 by aurelienb         #+#    #+#              #
#    Updated: 2021/02/21 11:44:50 by abrabant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC 		= clang
CFLAGS	=

TARGET	= libbmp.a

# Commands

RM		= /bin/rm -rf

# SRCS / OBJS

OBJ_DIR	= ./.obj

SRCS	= bmp_new.c bmp_encode_file.c bmp_int_rev_buf.c

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# RULES

all: $(TARGET)

$(TARGET): $(OBJ_DIR) $(OBJS)
	ar rcs $(TARGET) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o:%.c
	$(CC) $(CFLAGS) -c $< -g -o $@
