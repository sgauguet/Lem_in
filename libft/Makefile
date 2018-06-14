# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/02 22:52:43 by sgauguet          #+#    #+#              #
#    Updated: 2018/02/21 09:50:38 by sgauguet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
	  	ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_atoll.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_itoa_base_2.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_is_negative.c \
		ft_swap.c \
		ft_isblank.c \
		ft_islower.c \
		ft_isupper.c \
		ft_div_mod.c \
		get_next_line.c \

SRCS = printf/printf.c \
		printf/check.c \
		printf/types.c \
		printf/search_flags.c \
		printf/print_flags.c \
		printf/field_width.c \
		printf/conversions_1.c \
		printf/conversions_2.c \
		printf/conversions_3.c \
		printf/conversions_4.c \
		printf/bonus_conversions.c \
		printf/wchar.c \

OBJ = $(SRC:.c=.o)

OBJS = printf.o \
	   check.o \
	   types.o \
	   search_flags.o \
	   print_flags.o \
	   field_width.o \
	   conversions_1.o \
	   conversions_2.o \
	   conversions_3.o \
	   conversions_4.o \
	   bonus_conversions.o \
	   wchar.o \

FLAGS = -Wall -Wextra -Werror

HEADERS = libft.h \
			
all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRC) $(SRCS) -I $(HEADERS)
	ar rc $(NAME) $(OBJ) $(OBJS)

clean:
	@rm -f $(OBJ) $(OBJS)

fclean:
	@rm -f $(NAME) $(OBJ) $(OBJS)

re: fclean all

.PHONY: clean fclean re
