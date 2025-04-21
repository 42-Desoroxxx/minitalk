# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llage <desoroxxx@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 22:55:02 by llage             #+#    #+#              #
#    Updated: 2025/04/12 09:52:23 by llage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math -march=native -flto
NAME = Libft.a
AR = ar rcs

DEPS = includes
SRC = src
OBJ = obj

SRC_FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
   	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
	ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_tolower.c ft_toupper.c \
    ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
    ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
    get_next_line.c get_next_line_utils.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    print/ft_printf.c print/ft_print_special.c print/ft_print_basic.c \
    memory/s_alloc.c
SRCS := $(addprefix $(SRC)/,$(SRC_FILES))
OBJS := $(patsubst $(SRC)/%,$(OBJ)/%,$(SRCS:.c=.o))

all: $(NAME)

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) -I$(DEPS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Archiving$(RESET) $@..."
	@$(AR) $@ $^
	@echo "$(GREEN)Done!$(RESET)"

bonus: all

clean:
	@echo "$(RED)Cleaning$(RESET) object files..."
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)Removing$(RESET) $(NAME)..."
	@rm -f $(NAME)

re: fclean
	@$(MAKE) --no-print-directory all


