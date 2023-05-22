# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:09:44 by jtorre-s          #+#    #+#              #
#    Updated: 2023/05/22 12:34:50 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(addprefix $(SRC_DIR)/, ${SRC:.c=.o})

NAME = pipex

CC = gcc -Werror -Wall -Wextra

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINT_DIR = ../ft_printf42
PRINTF = $(PRINT_DIR)/ft_printf.a

SRC_DIR = .

CFLAGS =  -Wall -Wextra -Werror

SRC = pipex.c

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -L ./libft -l ft  -o $(NAME)
	$(CC) $(OBJ) -L ./ft_printf42 -l ft  -o $(NAME)
	

$(LIBFT):
	make -C $(LIBFT_DIR)

all : $(NAME)

clean:
		/bin/rm -f $(OBJ)
	
fclean: clean
		make -C $(LIBFT_DIR) fclean
		/bin/rm -f $(NAME)
		
re: fclean all

.PHONY: all clean fclean re