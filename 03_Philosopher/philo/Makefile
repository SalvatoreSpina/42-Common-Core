NAME = philo

SRC = philosopher.c init.c \
	fake_libft.c time.c \
	checker.c no_leak_please.c \
	routine.c

HEADER = philosopher.h

OBJ = $(SRC:.c=.o)

FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	@gcc $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$@ built"

%.o : %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Obj cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "All cleaned"

re: fclean all