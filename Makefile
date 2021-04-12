# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 19:42:38 by heusebio          #+#    #+#              #
#    Updated: 2020/07/23 20:14:14 by heusebio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_print_c.c \
		ft_print_uint.c \
		ft_put_all.c \
		ft_strlen.c \
		ft_isdigit.c \
		ft_print_d_i.c \
		ft_print_p.c \
		ft_print_x.c \
		ft_len_digit.c \
		ft_printf.c \
		ft_print_s.c \
		ft_processor.c \
		ft_strchr_print_c.c \
		ft_print_max_digit.c

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

OBJ = $(SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
