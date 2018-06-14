# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 17:13:05 by sgauguet          #+#    #+#              #
#    Updated: 2018/06/13 12:16:59 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = lem_in.c \
	  instructions.c \
	  check_rooms.c \
	  rooms.c \
	  links.c \
	  comments.c \
	  error.c \
	  search_path.c \
	  ant.c \
	  solve.c \
	  solve_2.c \
	  sort.c \
	  free_mem.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = lem_in.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libft/ all
	gcc $(FLAGS) -c $(SRC) -I libft/
	gcc -o $(NAME) $(OBJ) -I libft/ -L libft/ -lft

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: 
	make -C libft/ fclean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY:	all clean fclean re
