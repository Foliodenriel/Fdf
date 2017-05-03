# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abara <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 14:45:39 by abara             #+#    #+#              #
#    Updated: 2017/02/21 15:22:57 by abara            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c draw.c help.c map.c object_rotate.c render.c \
	  vector.c matrice.c parse.c move.c press.c

LIB = -g -lmlx -framework OpenGL -framework AppKit -lm

LIBFT = libft/libft.a

PATH_SRC = sources/

PATH_LIB = libs/

all: $(NAME)

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@make -C libs/libft/
	@gcc -o $(NAME) $(FLAGS) $(addprefix $(PATH_LIB), $(LIBFT)) $(addprefix $(PATH_SRC), $(SRC)) $(LIB)

clean:
	@make clean -C libs/libft/

fclean: clean
	@make fclean -C libs/libft/
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
