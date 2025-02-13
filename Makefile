# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carlossalazar <carlossalazar@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 13:56:08 by carlossalaz       #+#    #+#              #
#    Updated: 2025/02/13 20:34:00 by carlossalaz      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = include
CC = cc
FLAGS = -g3 -Wall -Wextra -Werror -pthread -fsanitize=thread
RM = rm -f
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/

SRC_FILES = main.c init.c simulation.c philo.c monitor.c utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(INCLUDE) -L $(LIBFT) -lft
	@echo "$(NAME) built successfully!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus