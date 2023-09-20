# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 17:09:44 by jtorre-s          #+#    #+#              #
#    Updated: 2023/09/07 16:18:24 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ = $(addprefix $(SRC_DIR)/, ${SRC:.c=.o})

NAME = pipex

CC = gcc -Werror -Wall -Wextra

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src

CFLAGS =  -Wall -Wextra -Werror

SRC = pipex.c pipex_utils.c

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(OBJ) -L ./libft -l ft  -o $(NAME)
	
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