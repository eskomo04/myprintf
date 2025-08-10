# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 03:00:11 by eskomo            #+#    #+#              #
#    Updated: 2025/08/10 06:00:14 by eskomo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_print_digit.c ft_print_unsignd.c
OBJ = $(SRC:.c=.o)

# Path to your libft (assumed to be in ./libft)
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


test: $(NAME) Loeschen.c
	$(CC) $(CFLAGS) Loeschen.c $(NAME) -o test.out
	./test.out



clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re