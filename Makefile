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

SOURCES =	checks.c free.c ft_atol.c ft_split.c implementation_utils.c\
			implementation_utils.c implementation.c insert_stack.c main.c\
			push_swap.c push.c reverse_rotate.c rotate.c stack_utils.c swap.c

OBJECTS = $(SOURCES:.c=.o)
NAME = push_swap
ARCHIVE = push_swap.a

all: $(NAME)

$(NAME): $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE): $(OBJECTS)
	ar -rcs $(ARCHIVE) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(ARCHIVE)

fclean: clean
	rm -f $(NAME)

re: all

.PHONY: all clean fclean re
