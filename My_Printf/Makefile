NAME = libftprintf.a

SRCS = ft_printf.c ft_strlen.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c \
ft_memcpy.c ft_printf/dec_to_hex.c ft_printf/check_flags.c ft_printf/flags.c\
ft_printf/ft_putunbr_fd.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all