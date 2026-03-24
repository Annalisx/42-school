
NAME = push_swap
LIBFT = ./libft/libft.a
INCLUDES = -I./includes -I./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c sort.c push.c swap.c rotate.c reverse_rotate.c initialize_utils.c execute.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS}
	make -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	make -C ./libft clean
	${RM}	${OBJS}	

fclean: clean
	make -C ./libft fclean
	${RM}	${NAME}	

re: fclean	all

.PHONY:	all	clean	fclean	re
