NAME = libftprintf.a 
LIBFT = ./libft/libft.a
INCLUDES = -I./includes -I./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs
RM = rm -f

SRCS = ft_printf.c ft_utils.c ft_utils2.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS}
	make -C ./libft
	cp ${LIBFT} ${NAME}
	${LIBC}	${NAME}	${OBJS}

all: ${NAME}

clean:
	make -C ./libft clean
	${RM}	${OBJS}	

fclean: clean
	make -C ./libft fclean
	${RM}	${NAME}	

re: fclean	all

.PHONY:	all	clean	fclean	re