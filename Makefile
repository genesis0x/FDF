# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 17:11:56 by hahadiou          #+#    #+#              #
#    Updated: 2023/01/06 15:33:11 by hahadiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =  fdf

CC        = gcc
FLAGS    = -Wall -Wextra -Werror -Iinc -Ilibft 

inc			= ./inc/fdf.h

LIBFT		= libft/libft.a

SRCS        = 		src/main.c \
						src/init.c \
						src/parse_map.c \
						src/put_pixel.c \
						src/transform_ref.c \
						src/utils.c \
						src/event_hooks.c

OBJS        = $(SRCS:.c=.o)

.c.o: 
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
RM		    = rm -f

all:		${NAME}

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${OBJS}  ${LIBFT} -lmlx -framework OpenGL -framework AppKit -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

run:
			@clear && make re &&  make clean && ./fdf

clean:
			@ ${RM} ${OBJS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)OBJS ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)Binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re
