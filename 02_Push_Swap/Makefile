SRC_COMMON = 	./src/both/commands/ft_puterr.c \
				./src/both/commands/pa.c \
				./src/both/commands/pb.c \
				./src/both/commands/ra.c \
				./src/both/commands/rb.c \
				./src/both/commands/rr.c \
				./src/both/commands/rra.c \
				./src/both/commands/rrb.c \
				./src/both/commands/rrr.c \
				./src/both/commands/sa.c \
				./src/both/commands/sb.c \
				./src/both/commands/ss.c \
				./src/both/arg.c \
				./src/both/free.c \
				./src/both/stack_operator.c \
				./src/both/fake_libft/fake_libft1.c \
				./src/both/fake_libft/fake_libft2.c \
				./src/both/fake_libft/fake_libft3.c

SRC_SORTER =	./src/push_swap/loop.c \
				./src/push_swap/main.c \
				./src/push_swap/sort.c \
				./src/push_swap/five.c \
				./src/push_swap/index.c \
				./src/push_swap/rotate.c \
				./src/push_swap/util.c

SRC_CHECKER =	./src/bonus/checker.c \
				./src/bonus/main.c


OBJS_COMMON	= ${SRC_COMMON:.c=.o}
OBJS_SORTER		= ${SRC_SORTER:.c=.o}
OBJS_CHECKER	= ${SRC_CHECKER:.c=.o}

INCLUDE = ./src/headers

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
NAME_CHECKER = checker

CC = gcc
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS_COMMON) $(OBJS_SORTER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJS_COMMON) $(OBJS_SORTER)

$(NAME_CHECKER): $(OBJS_COMMON) $(OBJS_CHECKER)
			${CC} $(CFLAGS) -I$(INCLUDE) -o $(NAME_CHECKER) $(OBJS_COMMON) $(OBJS_CHECKER)

clean:
			${RM} ${OBJS_COMMON} ${OBJS_SORTER} ${OBJS_CHECKER}

fclean: clean
			${RM} ${NAME} ${NAME_CHECKER}

re: fclean all

bonus: checker

.PHONY:		bonus all clean fclean re