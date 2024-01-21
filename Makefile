# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:35:15 by jnuncio-          #+#    #+#              #
#    Updated: 2024/01/21 23:53:06 by jnuncio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# HIGHLIGHTING COLOR

HL_GREEN = $(shell tput setab 2)
HL_CYAN = $(shell tput setab 6)

# FONT COLOR

RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
RESET = $(shell tput sgr0)

NAME = philo
BIN	= bin
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g
LFLAGS = -pthread #-fsanitize=thread
RM = rm -rf
SRC = $(addprefix src/, main.c\
	utils.c\
	init.c\
	supervisor.c\
	exit.c)
OBJ = $(SRC:src/%c=bin/%o)

all: $(BIN) $(NAME)

$(NAME): $(OBJ)
	@echo -n "Compiling philo... "
	@$(CC) $(OBJ) $(LFLAGS) -o $(NAME) &&\
	echo "$(GREEN)OK!$(RESET)" || echo "$(RED)KO!$(RESET)"

$(BIN):
	@echo "------------------------------------------------------"
	@echo "$(HL_CYAN)philo:$(RESET)";
	@test -d $(BIN) || (mkdir -p $(BIN) &&\
	echo "$(GREEN)Created $(BIN) directory.$(RESET)") ||\
	echo "$(RED)Failed to create $(BIN) directory.$(RESET)"

$(BIN)/%o: src/%c
	@$(CC) -c $< $(CFLAGS) -o $@

clean: hl_philo
	@if [ -n "$(wildcard bin/*.o)" ]; then \
		$(RM) $(OBJ); \
		echo "$(GREEN)deleted object files$(RESET)"; \
	elif [ ! -n "$(wildcard bin/*.o)" ] && ([ -e philo ]); then \
		echo "$(YELLOW)there are no object files$(RESET)"; \
	fi
	@test -d $(BIN) && $(RM) $(BIN) &&\
	echo "$(GREEN)deleted $(BIN) directory$(RESET)" || true
	
fclean: clean hl_philo
	@test -e philo && $(RM) philo &&\
	echo "$(GREEN)deleted philo$(RESET)" || true

hl_philo:
	@echo "------------------------------------------------------"
	@if [ ! -n "$(wildcard bin/*.o)" ] && [ ! -e philo ]; then \
		echo "$(HL_CYAN)philo:$(RESET)$(YELLOW) nothing to clean$(RESET)"; \
	else \
		echo "$(HL_CYAN)philo:$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re