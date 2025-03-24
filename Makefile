# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amzahir <amzahir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/23 08:48:45 by amzahir           #+#    #+#              #
#    Updated: 2025/03/23 08:49:14 by amzahir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = 

NAME = fractol

DEP = fractol.h

all : $(NAME)

%.o: %.c $(DEP)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): server client

server: server.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

client: client.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY:
	all clean fclean re