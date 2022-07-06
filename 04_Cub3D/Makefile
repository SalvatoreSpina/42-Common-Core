NAME		=	cub3D

SRCS_COMMON = 	checker/initialiser.c \
				checker/informations.c \
				checker/map.c \
				checker/parsing.c \
				checker/parsing_2.c \
				raycasting/raycasting.c \
				aux/colors.c \
				aux/color_math.c \
				aux/errors.c \
				aux/hooks.c \
				aux/hooks_mouse.c \
				aux/fake_mlx.c \
				aux/minimap.c \
				aux/aux.c \
				fake_libft/fake_libft1.c \
				fake_libft/fake_libft2.c \
				fake_libft/fake_libft3.c

SRCS		=	cub3d.c \
				raycasting/rendering.c \
				raycasting/move.c \
				checker/map_2.c \
				${SRCS_COMMON}

SRCS_BONUS = 	${SRCS_COMMON} \
				cub3d_bonus.c \
				addons/anim.c \
				addons/entity.c \
				addons/update.c \
				addons/render.c \
				addons/rendering.c \
				addons/move.c \
				addons/map_2.c \
				addons/rendering_2.c

HEADER		=	cub3d.h

LIBFT		=	libft.a
LIBFTDIR	=	./libft/

MLX			=	libmlx.a

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -I./ -Ofast -fno-strict-aliasing -fomit-frame-pointer -mtune=native -msse4.2 -mfpmath=sse -march=native -funsafe-math-optimizations -funroll-loops -ffast-math -flto -finline-functions -DRENDERER_THREAD_COUNT=10 -g
MLXFLAGS	=	-Llibft -Lmlx -lmlx -framework OpenGL -framework Appkit 

ifndef WITH_BONUS
	OBJS = $(SRCS:.c=.o)
else
	OBJS = $(SRCS_BONUS:.c=.o)
	CFLAGS += -DBONUS
endif

all: $(NAME)

bonus:
	@make WITH_BONUS=1 all

$(NAME): $(OBJS) $(HEADER)
	@make -C ./libft/
	@make -C ./mlx/
	$(CC) $(CFLAGS) $(LIBFTDIR)$(LIBFT) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(SRCS:.c=.o)
	rm -f $(SRCS_BONUS:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all

subject:
	make
	./cub3D maps/subject.cub

quicktest:
	make
	./cub3D maps/quicktest.cub

castle:
	make
	./cub3D maps/castle.cub

cave:
	make
	./cub3D maps/cave.cub

nether:
	make
	./cub3D maps/nether.cub

sus:
	make bonus
	./cub3D maps/amongus.cub

.PHONY: all clean fclean re
