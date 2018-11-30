# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 23:24:40 by mgessa            #+#    #+#              #
#    Updated: 2018/11/30 23:42:53 by mgessa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c \
	   parser.c \
	   loader.c \
	   ft_checkf_sz.c \
	   ft_checkf_tet.c \
	   ft_checkf_tside.c \
	   ft_load_tet.c \
	   ft_load_tetmap.c \
	   ft_load_blocks.c \
	   ft_resolve.c \
	   ft_perfect_square.c \
	   ft_show_tab.c \
	   ft_create_array.c

FLAGS = -Wall \
		-Werror \
		-Wextra

OBJS = $(SRCS:.c=.o)

HEADER = ./

all: libft $(NAME)

libft:
	(cd libft; make all)

re-libft:
	cd libft && make re

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $^ -L. libft/libft.a

./%.o: ./%.c
	gcc $(FLAGS) -c $^ -I $(HEADER) -I ./libft/

clean:
	/bin/rm -f $(OBJS)
	cd libft && make clean

fclean: clean
	/bin/rm -f $(NAME)
	cd libft && make fclean

re: fclean re-libft all

.PHONY: all clean re fclean libft
