
NAME = codexion
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -pthread -I.
RM = rm -f

SRCS = main.c parsing/parsing.c parsing/parsing2.c parsing/prints.c

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
