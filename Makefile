# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 16:43:16 by zwalad            #+#    #+#              #
#    Updated: 2022/03/15 21:29:04 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := gcc

FLAGS := -Wall -Wextra -Werror

RM = @rm -f

SRC := main.c \
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


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME) $(FLAGS) -g -fsanitize=address

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
