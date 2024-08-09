# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhocsak <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/09 19:06:46 by bhocsak           #+#    #+#              #
#    Updated: 2024/08/09 19:07:32 by bhocsak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES =	#Fill thatp

OBJECTS = $(SOURCES:.c=.o)
NAME = .a   #Fill that up

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
