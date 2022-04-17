CC = gcc

NAME = so_long

LIBFTNAME = libft.a

CFLAGS = -Werror -Wall -Wextra

MINILIBX = -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

OBJS := $(*.o)

SRC = main.c

MAPTOOLS = ./map/ft_get_map.c ./map/ft_check_map_file.c ./map/ft_map_val_utilities.c \
./map/ft_check_map_valid.c

RENDERSRC = ./render/hooks.c ./render/ft_control.c ./render/ft_keycode.c ./render/ft_render.c \
./render/ft_window.c ./render/ft_logic.c ./render/ft_put_img.c ./render/ft_images.c ./render/ft_player.c \
./render/ft_wall.c ./render/ft_render_basic.c ./render/ft_game_over.c ./render/pseudordm.c

BONUSSRC = ./bonus/ft_bonus.c ./bonus/ft_animate.c ./bonus/ft_img_enemy.c ./bonus/ft_put_enemy.c ./bonus/ft_move_enemy.c

LIBFTPATH = ./libft/

all: $(NAME)

${NAME}: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${RENDERSRC} ${BONUSSRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=0

clean:
	rm -rf *.o

bonus: fclean
	make -C ${LIBFTPATH}
	mv $(LIBFTPATH)${LIBFTNAME} ${LIBFTNAME}
	${CC} ${CFLAGS} ${SRC} $(MAPTOOLS) ${RENDERSRC} ${BONUSSRC} ${LIBFTNAME} ${MINILIBX} -o ${NAME} -D BONUS=1

fclean: clean
	rm -f $(LIBFTNAME) ${OBJS} $(NAME)

re: fclean ${NAME}