# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sazanjan <sazanjan@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 16:45:45 by codespace         #+#    #+#              #
#    Updated: 2025/07/30 17:18:12 by sazanjan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library file that will be created
NAME = libftprintf.a

# List of all source files
SRC = ft_printf.c ft_helpers.c

# Name of the object files (we replace .c with .o)
OBJ = $(SRC:.c=.o)

# Compiler and flags (show all warnings, treat warnings as errors)
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default rule — this is what runs when you type just `make`
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Clean rule — deletes object files
clean:
	rm -f $(OBJ)

# Fclean — deletes everything, including the library
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all
