/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:10:41 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:16 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_render_enemy(t_render_v **vars, t_game_map **map)
{
	int			pos[2];
	static int	rand;

	if (BONUS == 1)
	{
		rand = ft_pseudordm() % 5;
		ft_enemy1(vars, map);
		if (rand == 1)
			ft_enemy2(vars, map);
		pos[0] = ((*map)->enemy_pos[0] * TILE_WIDTH);
		pos[1] = ((*map)->enemy_pos[1] * TILE_WIDTH);
		ft_put_img(vars, (*map)->enemy, pos[0], pos[1]);
	}
}

static void	ft_put_player(t_render_v **vars, t_game_map *game_map)
{
	int	pos[2];

	pos[0] = game_map->player_position_x;
	pos[1] = game_map->player_position_y;
	ft_put_img(vars, game_map->trainer, pos[0], pos[1]);
}

static void	ft_tile(char t, t_render_v **v, int *pos, t_game_map **map)
{
	(*map)->draw_p++;
	ft_put_img(v, (*map)->bg, pos[0], pos[1]);
	if (t == '1')
	{
		ft_wall1(v, map);
		if ((*map)->draw_p % 2)
			ft_wall2(v, map);
		if ((*map)->draw_p % 3)
			ft_wall3(v, map);
		ft_put_img(v, (*map)->wall, pos[0], pos[1]);
	}
	if (t == 'C')
		ft_put_img(v, (*map)->collec, pos[0], pos[1]);
	if (t == 'E')
		ft_put_img(v, (*map)->exit, pos[0], pos[1]);
}

static void	ft_draw_content(t_render_v **vars, t_game_map *game_map)
{
	int		count;
	int		char_counter;
	char	current;
	int		pos[2];

	ft_set_startv_render(&count, &char_counter);
	pos[0] = 0;
	pos[1] = 0;
	game_map->draw_p = 0;
	while (count <= game_map->map_height && vars)
	{
		char_counter = 0;
		pos[0] = 0;
		while (game_map->map_data[count][char_counter] != 0)
		{
			current = game_map->map_data[count][char_counter];
			ft_tile(current, vars, pos, &game_map);
			char_counter++;
			pos[0] += TILE_WIDTH;
		}
		pos[1] += TILE_WIDTH;
		count++;
	}
	ft_render_enemy(vars, &game_map);
	ft_put_player(vars, game_map);
}

void	ft_render_basic(t_game_map *game_map, t_render_v **vars)
{
	void	*p[2];
	char	*go;

	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	go = "You won!";
	if (game_map->map_data && vars && (!game_map->game_over))
	{
		mlx_clear_window((*vars)->mlx, (*vars)->win);
		if ((!ft_game_over(&game_map, vars)) && p[0] && p[1])
		{
			ft_animate(&game_map, vars);
			ft_pseudordm();
			ft_if_putenemy(&game_map);
			ft_draw_content(vars, game_map);
			ft_put_steps(vars, &game_map);
			if (BONUS)
				ft_move_enemy(&game_map);
		}
	}
}
