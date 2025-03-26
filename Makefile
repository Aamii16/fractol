# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 08:48:45 by amzahir           #+#    #+#              #
#    Updated: 2025/03/26 09:01:50 by amzahir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = hooks_utils.o string_utils.o render_utils.o mandelbrot.o julia.o main.o

NAME = fractol

DEP = fractol.h

all : $(NAME)

%.o: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): fractol

fractol: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean fractol

.PHONY:
	all clean fclean re