SRC = 	main.c 

NAME = push_swap
OBJS = ${SRC:.c=.o}
CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft


all: ${NAME} 

libft:
	${MAKE} -C ${LIBFT_PATH}

.c.o: 
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}


push_swap: ${OBJS} libft
	${CC} ${OBJS} -Werror -Wextra -Wall -o push_swap -L./libft -lft

clean:
	${MAKE} -C ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean:	clean
	${MAKE} -C ${LIBFT_PATH} fclean
	${RM} ${NAME}
	${RM} push_swap

re: fclean all

.PHONY: all clean fclean re libft
