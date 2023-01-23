# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 11:14:53 by hahadiou          #+#    #+#              #
#    Updated: 2023/01/21 18:52:39 by hahadiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLAGS	= -Wall -Wextra -Werror

NAME	= fdf

INC	= inc
LIBFT_PATH	= libft
SRC_PATH	= src
OBJ_PATH	= obj

SRCS = event_hooks.c \
		init.c \
		main.c \
		parse_map.c \
		put_pixel.c \
		transform_ref.c \
		utils.c \
		#draw.c
		
SRC		= $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ		= $(addprefix $(OBJ_PATH)/,$(SRCS:.c=.o))

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

all: $(NAME)


$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling Libft...$(NOC)"
	@make -sC $(LIBFT_PATH)
	@echo "$(YELLOW)Compiling FDF...$(NOC)"
	@$(CC) $(FLAGS) -L $(LIBFT_PATH) -lmlx -framework OpenGL -framework AppKit -o $@ $^ -lft
	@echo "$(GREEN)$@$(NOC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)/$(NAME).h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(INC) -c -o $@ $<

run :
		make re && ./fdf
clean:
	@echo "$(RED)Deleting FDF OBJS ✔️ $(NOC)"
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJB_PATH)

fclean: clean
	@echo "$(RED)Deleting FDF Binary$(NOC)"
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME) ${NAMEB}

re: fclean all


.PHONY:	all clean fclean re  
