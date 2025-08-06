# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eskomo <eskomo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/06 03:00:11 by eskomo            #+#    #+#              #
#    Updated: 2025/08/06 03:22:58 by eskomo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = printf

LIBFT_DIR = libft


LIBFT_OBJS = \
	$(LIBFT_DIR)/ft_putnbr.o

SRC = ft_printf.c ft_print_hex.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

all: $(LIBFT_DIR) $(NAME)

$(LIBFT_DIR):
	$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(OBJ) $(LIBFT_OBJS)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
