NAME        = libft.a

CC          = cc

CFLAGS      = -Wall -Wextra -Werror -IINC

INC         =   ./libft.h

SRCS        =      ft_atoi.c \
                          ft_bzero.c \
                          ft_calloc.c \
                          ft_isalnum.c \
                          ft_isalpha.c \
                          ft_isascii.c \
                          ft_isdigit.c \
                          ft_isprint.c \
                          ft_itoa.c \
                          ft_lstadd_back.c \
                          ft_lstadd_front.c \
                          ft_lstclear.c \
                          ft_lstdelone.c \
                          ft_lstiter.c \
                          ft_lstlast.c \
                          ft_lstmap.c \
                          ft_lstnew.c \
                          ft_lstsize.c \
                          ft_memchr.c \
                          ft_memcmp.c \
                          ft_memcpy.c \
                          ft_memmove.c \
                          ft_memset.c \
                          ft_putchar_fd.c \
                          ft_putendl_fd.c \
                          ft_putnbr_fd.c \
                          ft_putstr_fd.c \
                          ft_split.c \
                          ft_strchr.c \
                          ft_strcpy.c \
                          ft_strdup.c \
                          ft_striteri.c \
                          ft_strjoin.c \
                          ft_strlcat.c \
                          ft_strlcpy.c \
                          ft_strlen.c \
                          ft_strmapi.c \
                          ft_strncmp.c \
                          ft_strnstr.c \
                          ft_strrchr.c \
                          ft_strtrim.c \
                          ft_substr.c \
                          ft_tolower.c \
                          ft_toupper.c \
                          get_next_line.c \
                          get_next_line_utils.c \
                          ft_dprintf.c
                          
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
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ar -rc $(NAME) $(OBJS) && make clean
			@echo "$(GREEN)$(NAME) Created[0m ✔️"

all:		${NAME}

clean:	
			@ ${RM} ${OBJS}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)OBJS ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)Binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


