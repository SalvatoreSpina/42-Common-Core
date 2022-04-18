SRC = 	sources/main.c \
		sources/input_checker.c \
		sources/handle_line.c \
		sources/util/close.c \
		sources/util/error.c \
		sources/util/free.c \
		sources/signal/signals.c \
		sources/lexer/lexer_environ.c \
		sources/lexer/lexer_string.c \
		sources/lexer/lexer_wildcard.c \
		sources/lexer/lexer.c \
		sources/lexer/token.c \
		sources/io/prompt.c \
		sources/exec/exec.c \
		sources/exec/execute.c \
		sources/exec/parser_redir.c \
		sources/exec/parser.c \
		sources/exec/path.c \
		sources/exec/process_context.c \
		sources/environ/environ_base.c \
		sources/environ/environ_helpers.c \
		sources/builtins/builtins.c \
		sources/builtins/cd.c \
		sources/builtins/echo.c \
		sources/builtins/env.c \
		sources/builtins/exit.c \
		sources/builtins/export.c \
		sources/builtins/pwd.c \
		sources/builtins/sspina.c \
		sources/builtins/unset.c

OBJS  = $(SRC:.c=.o)
NAME  = minishell
CC    = gcc
CFLAGS = -Wall -Wextra -Werror
READLINE_PATH = vendor/readline/
LIBS = -L$(LIBFT) -L$(READLINE_PATH)/lib -lreadline -lft

all: libs $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./includes -I$(LIBFT)includes/ -I$(READLINE_PATH)include -c $< -o $@

LIBFT = libs/libft/

libs: readline $(LIBFT)libft.a

libft: $(LIBFT)libft.a

readline: $(READLINE_PATH)

$(READLINE_PATH):
	sh ./install_readline.sh

$(LIBFT)libft.a:
	make -C $(LIBFT)

libs_clean:
	make -C $(LIBFT) clean

libs_fclean: libs_clean
	make -C $(LIBFT) fclean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(COMPILEFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: libs_fclean clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean libs readline libft libs_clean libs_fclean re



