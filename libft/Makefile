# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtorre-s <jtorre-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 18:46:48 by jtorre-s          #+#    #+#              #
#    Updated: 2023/05/25 16:41:28 by jtorre-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c	ft_strtrim.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_strmapi.c ft_hexa.c ft_number_un.c ft_number.c ft_printf.c ft_ptr.c \
		ft_putchar.c ft_string.c ft_variables.c
		
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstiter_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I.

NAME = libft.a

$(NAME): $(OBJ) 
		ar rcs $(NAME) $(OBJ)

all : $(NAME)

B = .

bonus: $(B)

$(B): $(OBJ) $(OBJBONUS)
		ar rcs $(NAME) $(OBJ) $(OBJBONUS)

clean:
		/bin/rm -f $(OBJ) $(OBJBONUS)
		
fclean: clean
		/bin/rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
