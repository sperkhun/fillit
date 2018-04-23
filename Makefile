#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/17 20:27:02 by sperkhun          #+#    #+#              #
#    Updated: 2017/12/17 20:28:45 by sperkhun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = main.c fillit.c vldfile.c division.c square.c ranking.c del.c randd.c\
	right.c down.c ft_arrdel.c ft_bzero.c ft_memset.c ft_isalpha.c\
	ft_lstdel.c ft_lstend.c ft_lstlen.c ft_lstnew.c ft_putchar.c ft_putstr.c\
	ft_strlen.c ft_strncpy.c ft_strnew.c ft_memcpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ):
	@gcc $(FLAGS) -c $(SRC)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all