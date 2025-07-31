# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazanjan <sazanjan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 16:45:45 by codespace         #+#    #+#              #
#    Updated: 2025/07/31 11:58:53 by sazanjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Name of the library
NAME = libftprintf.a

# Source and object files
SRC = ft_printf.c ft_helpers.c ft_hex.c
OBJ = $(SRC:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Rule to build the static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Delete object files
clean:
	rm -f $(OBJ)

# Delete object files and the library
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

# Phony targets
.PHONY: all clean fclean re
