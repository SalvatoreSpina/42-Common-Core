NAME		= pipex

CFLAGS		= -Wall -Wextra -Werror

SRCS		= pipex.c \
			  exec.c \
			  error.c \
			  fct.c

OBJS		= $(SRCS:.c=.o)

LIBFTPATH	= ./libft/
LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)
LIBFT		= -L$(LIBFTPATH) -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBFTMAKE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(LIBFTMAKE) clean
	$(RM) $(OBJS)

fclean: clean
	$(LIBFTMAKE) fclean
	$(RM) $(NAME)

re: fclean all