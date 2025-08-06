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



# Name of the final executable
NAME = printf

# Path to the libft directory
LIBFT_DIR = libft

# Libft object files
LIBFT_OBJS = \
	$(LIBFT_DIR)/ft_putnbr.o
# Add more .o files as needed

# Main object file(s)
SRC = ft_printf.c ft_print_hex.c         # or ft_printf.c
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Default target
all: $(LIBFT_DIR) $(NAME)

# Build the libft .o files using its Makefile if present
$(LIBFT_DIR):
	$(MAKE) -C $(LIBFT_DIR)

# Link the final executable
$(NAME): $(OBJ) $(LIBFT_OBJS)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT_OBJS)

# Compile main.c or ft_printf.c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything including executable
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
