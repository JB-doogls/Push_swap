# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 22:15:18 by jbdoogls          #+#    #+#              #
#    Updated: 2020/06/01 19:14:50 by jbdoogls         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----- Name -----
LIBFT_NAME		= libft.a
HEADER_NAME		= ft_push_swap.h
PS_NAME			= push_swap
CHECK_NAME		= checker
# =================

# ----- Dir -----
LIBFT_DIR		= ./libft/
INC_DIR			= ./includes/
SRC_DIR			= ./src/
OBJ_DIR			= ./obj/
# =================

# ---- Lists ----
PS_FUNCS		= handle_a.c insertion_sort.c lowcoster.c operations.c push_pop.c \
					sort_tools.c stack_func.c utils.c validation.c visualization.c push_swap.c

CHECK_FUNCS		= handle_a.c insertion_sort.c lowcoster.c operations.c push_pop.c \
					sort_tools.c stack_func.c utils.c validation.c visualization.c checker.c
# =================

# ---- Auto ----
HEADER			= $(addprefix $(INC_DIR), $(HEADER_NAME))
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

PS_SRC			= $(addprefix $(SRC_DIR), $(PS_FUNCS))
CHECK_SRC		= $(addprefix $(SRC_DIR), $(CHECK_FUNCS))
PS_OBJ			= $(addprefix $(OBJ_DIR), $(PS_FUNCS:.c=.o))
CHECK_OBJ		= $(addprefix $(OBJ_DIR), $(CHECK_FUNCS:.c=.o))
# =================

# -------------
INCLUDES		= -I $(INC_DIR) -I $(LIBFT_DIR)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFT				= -L $(LIBFT_DIR) -lft

# --- Colors ---
RED				= "\033[0;31m"
GREEN			= "\033[0;32m"
CYAN			= "\033[0;36m"
EOC				= "\033[0m"
# =================

all: $(PS_NAME) $(CHECK_NAME)

$(PS_NAME):	$(LIBFT) $(OBJ_DIR) $(PS_OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) $(PS_OBJ) $(LFT) -o $(PS_NAME)
	@echo $(GREEN) "-$(PS_NAME) created"$(EOC)

$(CHECK_NAME): $(LIBFT) $(OBJ_DIR) $(CHECK_OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(CHECK_OBJ) $(LFT) -o $(CHECK_NAME)
	@echo $(GREEN) "-$(CHECK_NAME) created"$(EOC)

$(OBJ_DIR):
	@mkdir -p ./obj

FORCE:			;

$(LIBFT): FORCE
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	@echo $(CYAN) "Compiling $< into $@"$(EOC)
	
clean:
	@/bin/rm -rf $(OBJ_DIR)
	@echo $(RED) "push_swap project object files deleted"$(EOC)
	@make clean -C $(LIBFT_DIR)
	

fclean:	clean
	@/bin/rm -rf $(PS_NAME) $(CHECK_NAME)
	@echo $(RED) "push_swap project executable files deleted"$(EOC)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY:			all clean fclean re