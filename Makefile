NAME        =  fdf

CC        = gcc
FLAGS    = -Wall -Wextra -Werror -Iinc -Ilibft 

inc			= ./inc/fdf.h

SRCS        = 		src/main.c \
						src/init.c \
						src/parse_map.c \
						src/put_pixel.c \
						src/transform_ref.c \
						src/utils.c \
						libft/get_next_line.c \
						libft/get_next_line_utils.c 


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
			@${CC} ${OBJS}   -lmlx -framework OpenGL -framework AppKit -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

run:
			@clear && make re && ./fdf

clean:
			@ ${RM} ${OBJS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)OBJS ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)Binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re