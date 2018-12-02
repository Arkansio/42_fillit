# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgessa <mgessa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 23:24:40 by mgessa            #+#    #+#              #
#    Updated: 2018/12/02 20:02:01 by mgessa           ###   ########.fr        #
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
	   ft_create_array.c \
	   free_map.c \
	   free_int_map.c

FLAGS = -Wall \
		-Werror \
		-Wextra

OBJS = $(SRCS:.c=.o)

HEADER = ./

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) -o $(NAME) $^ -L. libft/libft.a

./%.o: ./%.c
	gcc $(FLAGS) -c $^ -I $(HEADER) -I ./libft/

clean:
	/bin/rm -f $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean re fclean libft
