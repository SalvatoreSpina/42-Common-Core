NAME =		span

COMP =		c++
CFLAGS =	-Wall -Werror -Wextra -std=c++98

SRCS =		main.cpp Span.cpp

OBJS =		$(SRCS:%.cpp=%.o)

$(NAME):	$(SRCS)
	$(COMP) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)