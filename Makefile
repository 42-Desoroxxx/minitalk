# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llage <llage@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 22:55:02 by llage             #+#    #+#              #
#    Updated: 2025/04/12 04:01:45 by llage            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math -march=native -flto
DEPS = includes
SRC = src
OBJ = obj

CLIENT = client
SERVER = server

SRC_CLIENT = $(SRC)/client.c
SRC_SERVER = $(SRC)/server.c

OBJ_CLIENT = $(OBJ)/client.o
OBJ_SERVER = $(OBJ)/server.o

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT) Libft/Libft.a
	@echo "$(GREEN)Linking$(RESET) $@..."
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) Libft/Libft.a -o $@

$(SERVER): $(OBJ_SERVER) Libft/Libft.a
	@echo "$(GREEN)Linking$(RESET) $@..."
	@$(CC) $(CFLAGS) $(OBJ_SERVER) Libft/Libft.a -o $@

$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p $(@D)
	@echo "$(BLUE)Compiling$(RESET) $<..."
	@$(CC) $(CFLAGS) -I$(DEPS) -ILibft/includes -c $< -o $@

Libft/Libft.a:
	@$(MAKE) -s -C Libft

bonus: all

clean:
	@echo "$(RED)Cleaning$(RESET) object files..."
	@rm -rf $(OBJ)
	@$(MAKE) -s -C Libft clean

fclean: clean
	@echo "$(RED)Removing$(RESET) $(CLIENT) and $(SERVER)..."
	@rm -f $(CLIENT) $(SERVER)
	@$(MAKE) -s -C Libft fclean

re: fclean
	@$(MAKE) --no-print-directory all
