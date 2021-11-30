CC=gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f 
AR = ar rcs
SRCS = ft_printf.c ft_printfutils.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME) 

all: ${NAME}

.PHONY: clean fclean all bonus re
clean:
	-${RM} ${OBJS} $(OBJS) $(BONUSOBJS)
fclean: clean
	${RM} ${NAME}

re: fclean all
