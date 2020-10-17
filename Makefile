# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teva <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 15:37:03 by teva              #+#    #+#              #
#    Updated: 2020/10/17 15:18:04 by teva             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

FLAGS = -Wall -Werror -Wextra -g

SOURCE = main.c on_key_press.c read_file.c
SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/,$(SOURCE))

INCLUDES = ./includes/cub3d.h

LIB_PATH = ./libft
LIB_LINK = -I $(LIB_PATH) -L $(LIB_PATH) -lft

MLX_PATH = ./minilibx
MLX_LINK = -I $(MLX_PATH) -L $(MLX_PATH) -lmlx -framework OpenGL -framework AppKit -lz


OBJ = $(SOURCE:.c=.o)


$(NAME):
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	@gcc -c $(SRC) -I $(INCLUDES)
	@gcc $(FLAGS) $(MLX_LINK) $(LIB_LINK) $(OBJ) -o $(NAME)
	@mv ./minilibx/libmlx.dylib ./

all: $(NAME)

clean:
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME) libmlx.dylib

re: fclean all

.PHONY: all clean fclean re
