# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 03:00:11 by eskomo            #+#    #+#              #
#    Updated: 2025/08/12 02:28:19 by eskomo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_print_hex.c ft_print_unsignd.c ft_ptrptr.c
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
	$(CC) $(CFLAGS) Loeschen.c $(NAME) -o test.print
	./test.print



clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re