
NAME = codexion
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread
RM = rm -f

SRCS = main.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM}	${OBJS}	

fclean: clean
	${RM}	${NAME}	

re: fclean	all

.PHONY:	all	clean	fclean	re
