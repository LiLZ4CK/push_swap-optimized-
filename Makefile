# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:43:16 by zwalad            #+#    #+#              #
#    Updated: 2022/03/23 22:32:19 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

BONUSS := checker

CC := gcc

FLAGS := -Wall -Wextra -Werror

RM = @rm -f

SRC := push_swap.c \
		los_ab_hermanos.c \
		los_a_hermanos.c \
		los_b_hermanos.c \
		lst_utils.c \
		lil_libft.c \
		lil_libft2.c \
		lil_main.c \
		ps_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_help.c \
		ft_printf/ft_help2.c \
		ps_lot.c \
		ps_help.c \

BONS := check/checkerr.c \
		check/bonus_a_hermanos.c \
		check/bonus_b_hermanos.c \
		check/bonus_ab_hermanos.c \
		check/bonus_help.c \
		check/bonus_libft.c \
		check/bonus_libft2.c \
		check/lst_bonus.c \
		check/utils_bonus.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_help.c \
		ft_printf/ft_help2.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		get_next_line/get_next_line.h \

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME) $(FLAGS)

bonus: $(BONUSS)

 $(BONUSS): $(BONS)
	$(CC) $(BONS) -o $(BONUSS) $(FLAGS)


fclean:
	$(RM) $(NAME) $(BONUSS)

re: fclean all
