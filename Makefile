# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 22:15:18 by jbdoogls          #+#    #+#              #
#    Updated: 2020/06/01 14:44:37 by jbdoogls         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_NAME		= libft.a

LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

HEADER_NAME		= ft_push_swap.h
PS_NAME			= push_swap
CHECK_NAME		= checker

LIBFT_DIR		= ./libft/
INC_DIR			= ./includes/
SRC_DIR			= ./src/
OBJ_DIR			= ./obj/

PS_FUNCS		= handle_a.c insertion_sort.c lowcoster.c operations.c push_pop.c \
					sort_tools.c stack_func.c utils.c validation.c visualization.c push_swap.c

CHECK_FUNCS		= handle_a.c insertion_sort.c lowcoster.c operations.c push_pop.c \
					sort_tools.c stack_func.c utils.c validation.c visualization.c checker.c

HEADER			= $(addprefix $(INC_DIR), $(HEADER_NAME))

PS_SRC			= $(addprefix $(SRC_DIR), $(PS_FUNCS))
CHECK_SRC		= $(addprefix $(SRC_DIR), $(CHECK_FUNCS))
PS_OBJ			= $(addprefix $(OBJ_DIR), $(PS_FUNCS:.c=.o))
CHECK_OBJ		= $(addprefix $(OBJ_DIR), $(CHECK_FUNCS:.c=.o))

INCLUDES		= -I $(INC_DIR) -I $(LIBFT_DIR)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFT				= -L $(LIBFT_DIR) -lft

.PHONY:			all clean fclean re

all: $(PS_NAME) $(CHECK_NAME)

$(PS_NAME):	$(LIBFT) $(OBJ_DIR) $(PS_OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LFT) $(PS_OBJ) -o $(PS_NAME)

$(CHECK_NAME): $(LIBFT) $(OBJ_DIR) $(CHECK_OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(LFT) $(CHECK_OBJ) -o $(CHECK_NAME)

$(OBJ_DIR):
	@mkdir -p ./obj

FORCE:			;

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean:	clean
	@/bin/rm -rf $(PS_NAME) $(CHECK_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all