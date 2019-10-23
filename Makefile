# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 13:33:37 by mfierlaf          #+#    #+#              #
#    Updated: 2019/10/15 13:33:44 by mfierlaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = main.c mandelbrot.c

HEADERS = fractol.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make re -C ./libft
	@make clean
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -L libft/ -lft -L ./minilibx_macos \
	-lmlx -framework OpenGL -framework AppKit

clean:
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
