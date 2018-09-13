# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 08:39:51 by ksiziva           #+#    #+#              #
#    Updated: 2018/09/13 08:39:53 by ksiziva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
PATH_SRC = ./
PATH_OBJ = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_ls.c \
		ft_a.c \
		prints.c \
		ft_l.c \
		ft_noflags.c \
		ft_r.c \
		ft_rec.c \
		ft_flags.c \
		ft_sort.c \
		func.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C printf/
	@$(CC) $(CFLAGS) -I printf/ -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) printf/libftprintf.a
	@echo "$(NAME) created"

clean:
	@make -C printf/ clean
	@/bin/rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@make -C printf/ fclean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
