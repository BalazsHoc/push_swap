# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 19:06:46 by bhocsak           #+#    #+#              #
#    Updated: 2024/08/11 12:37:20 by bhocsak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES =

HEADER = push_swap.h

OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJECTS)
	 ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f $(NAME)

re: all

.PHONY: all clean fclean re
