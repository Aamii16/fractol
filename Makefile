# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 08:48:45 by amzahir           #+#    #+#              #
#    Updated: 2025/03/28 06:49:00 by amzahir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx_linux -O3
SRCS := string_utils.c render_utils.c hooks_utils.c mandelbrot.c julia.c main.c
OBJS := $(SRCS:.c=.o)

NAME = fractol

DEP = fractol.h

all : $(NAME)

%.o: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -lX11 -lXext -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY:
	all clean fclean re