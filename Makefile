SRCS	=	ft_printf.c			\
			ft_printf_utils.c	\
			conversions.c		\
			\

OBJS	=	${SRCS:.c=.o}

CC		=	gcc
CFLAGS	+=	-Wall -Werror -Wextra 
RM		=	rm -rf

NAME	= 	libftprintf.a

HEADERS	= 	./

.c.o	:	${SRCS}
			${CC} ${CFLAGS} -I ${HEADERS} -c $< -o $@

all	:		${NAME}

$(NAME) :	${OBJS}
			ar rcs ${NAME} ${OBJS}

bonus :		${OBJS}
			ar rcs ${NAME} ${OBJS} 

clean :	
			${RM} ${OBJS}

fclean :	clean 
			${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re