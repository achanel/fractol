NAME	= libft.a

HEADER = libft.h

SRCS	= ft_strdup.c ft_strncmp.c ft_strlen.c ft_memcpy.c ft_calloc.c ft_bzero.c ft_memset.c\
ft_atoi.c ft_atof.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_atoi.c ft_atof.c

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:	
		 	${CC} ${CFLAGS} -g -c $< -o $@

$(NAME):	${OBJS} 
					ar rcs ${NAME} $?

bonus:		${BONUS_OBJS} ${OBJS} 
					ar rcs ${NAME} $?
		
all:		${NAME} ${HEADER} 

clean:
					${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
					${RM} ${NAME}

re:					fclean all

.PHONY:		all clean fclean re bonus