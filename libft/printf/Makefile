# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 09:39:43 by sgauguet          #+#    #+#              #
#    Updated: 2018/02/27 11:13:56 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

SRC = printf.c \
	  check.c \
	  types.c \
	  search_flags.c \
	  print_flags.c \
	  field_width.c \
	  conversions_1.c \
	  conversions_2.c \
	  conversions_3.c \
	  conversions_4.c \
	  bonus_conversions.c \
	  wchar.c \

OBJ = $(SRC:.c=.o)

OBJS = ../*.o

HEADER = printf.h

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -c $(FLAGS) $(SRC) -I ../libft/ 
	gcc -o $(NAME) $(OBJ) $(OBJS)

clean :
	rm -f $(OBJ) printf

fclean :
	rm -f $(NAME) $(OBJ) printf

re : fclean all

.PHONY : all clean fclean re
