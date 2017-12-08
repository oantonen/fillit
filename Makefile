# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:03:40 by inovykov          #+#    #+#              #
#    Updated: 2017/12/07 18:20:22 by oantonen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =  main.c check_input.c record_fig.c \
		extra_functions.c \
		solving.c printing.c

OBJ = $(SRC:%.c=%.o)

HEADERS = fillit.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ)
	@echo "."
	@echo "."
	@echo "."
	@echo "All cookies were baked"

$(OBJ) : $(SRC)
	@gcc $(FLAGS) -c -I $(HEADERS) $(SRC) 

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "All clear"

re: fclean all
