# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etisha <etisha@student.21-school.>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 20:01:52 by etisha            #+#    #+#              #
#    Updated: 2022/02/16 20:01:59 by etisha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = src/so_long.h

HEADER_BONUS = src_bonus/so_long_bonus.h

NAME = so_long

SRC_FILES =	src/main.c src/exam.c src/get_next_line.c src/get_next_line_utils.c \
			src/savemap.c src/utils.c src/save.c src/window.c src/input.c

SRC_BONUS = src_bonus/main_bonus.c src_bonus/exam_bonus.c src_bonus/get_next_line_bonus.c \
			src_bonus/get_next_line_utils_bonus.c src_bonus/itoa_bonus.c \
			src_bonus/savemap_bonus.c src_bonus/utils_bonus.c src_bonus/save_bonus.c src_bonus/enemy_bonus.c \
			src_bonus/window_bonus.c src_bonus/rendering_bonus.c src_bonus/input_bonus.c src_bonus/go_bonus.c \
			src_bonus/rendering_2_bonus.c

MLX	   := -framework OpenGL -framework AppKit

MLXLIB = minilibx/libmlx.a 

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))

OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))

RM = rm -f

all: $(NAME)

$(NAME): $(MLXLIB) $(OBJ)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) $(MLXLIB) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLXLIB):
	@make -C minilibx/

bonus:
	@make HEADER="$(HEADER_BONUS)" SRC_FILES="$(SRC_BONUS)" all

clean:
	@make -C minilibx clean
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make -C minilibx clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
