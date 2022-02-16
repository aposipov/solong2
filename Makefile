# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchristi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 14:07:25 by lchristi          #+#    #+#              #
#    Updated: 2022/02/06 14:19:55 by lchristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
FLAGS = -Wall -Werror -Wextra
FLAGS_M = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

HEADER = ./inc/so_long.h ./inc/get_next_line.h

SRC = ./src/so_long.c ./src/check.c \
	./src/get_next_line.c ./src/get_next_line_utils.c\
	./src/draw.c ./src/movements.c ./src/search.c ./src/utils.c

OBJ = $(patsubst %.c,%.o,$(SRC))

RED='\033[4;31m'
GREEN='\033[0;32m'
NC='\033[0;0m'

all:	$(NAME)

$(NAME): 	$(OBJ)
			$(CC) $(FLAGS) $(FLAGS_M) $(OBJ) -o $(NAME)

%.o:	%.c Makefile $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) ${OBJ}
		@echo $(RED) *.o files is clean $(NC)

fclean:	clean
		$(RM) so_long
		@echo all files is clean!

re:	fclean all

.PHONY: all clean fclean re

