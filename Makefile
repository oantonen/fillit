# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:03:40 by inovykov          #+#    #+#              #
#    Updated: 2017/11/28 19:33:40 by inovykov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FIL_LIB = libfillit.a

SRC =  print_error.c check_input.c check_tetra.c ft_strlen.c ft_strncpy.c ft_strnew.c ft_sqrt.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(FIL_LIB) $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@ 

$(FIL_LIB) : $(OBJ)
	ar rc $(FIL_LIB) $(OBJ)
	ranlib $(FIL_LIB)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) main.c $(FIL_LIB)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
