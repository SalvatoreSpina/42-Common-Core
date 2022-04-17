# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sspina <sspina@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 15:13:57 by sspina            #+#    #+#              #
#    Updated: 2022/03/29 13:40:47 by sspina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror -c

SRCS = src/ft_print_ptr.c \
		src/ft_print_unsigned.c \
		src/ft_printf.c \
		src/ft_printf_utilities.c \
		src/ft_printhex.c

OBJECTS = $(SRCS:.c=.o)
LIB_PATH = ./libft
INCLUDES=./includes

all: $(NAME)

$(NAME): $(OBJECTS)
	@make re -C $(LIB_PATH)
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@/bin/rm -f $(OBJECTS)
	@make clean -C $(LIB_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all