NAME = libftprintf.a

SRCS = srcs/ft_printf.c srcs/ft_print_functions_one.c \
	srcs/ft_print_functions_two.c srcs/ft_utils.c

INCREMAKE = srcs/ft_printf.h Makefile

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ${INCREMAKE}
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${INCREMAKE}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all