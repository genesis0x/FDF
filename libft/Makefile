NAME        = libft.a

CC          = cc

CFLAGS      = -Wall -Wextra -Werror 

INC         =   ./libft.h

SRCS        =      ft_split.c \
                          ft_strchr.c \
                          ft_strdup.c \
                          ft_strjoin.c \
                          ft_strlen.c \
                          ft_substr.c \
                          get_next_line.c \
                          
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

${NAME}:	${OBJS}
			@ar -rc $(NAME) $(OBJS)

all:		${NAME}

clean:	
			@ ${RM} ${OBJS}

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


