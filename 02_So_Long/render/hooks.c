/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:05:50 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:20 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	exit_hook(void)
{
	ft_free_stuff(NULL, NULL);
	exit(0);
}

void	ft_build_img(t_game_map **map, t_render_v **vars)
{
	ft_bottle_image(vars, map);
	ft_wall_image(vars, map);
	ft_exit_image(vars, map);
	ft_bg_image(vars, map);
	ft_trainer_img(vars, map);
	ft_enemy1(vars, map);
	ft_animate(map, vars);
}

static int	key_hook(int keycode, t_render_v **vars)
{
	static t_game_map	*game_map;
	static t_render_v	*varsm;

	if ((*vars))
		varsm = (*vars);
	if (keycode == 53)
	{
		mlx_destroy_window((*vars)->mlx, (*vars)->win);
		ft_free_stuff(NULL, NULL);
		exit(0);
		return (0);
	}
	if (varsm)
	{
		game_map = ft_control_player(keycode, NULL);
		ft_render_basic(game_map, &varsm);
	}
	ft_pseudordm();
	return (1);
}

static t_render_v	*ft_init_window(t_game_map *game_map)
{
	t_render_v	*vars;
	int			ww;
	int			wh;

	vars = malloc(sizeof(t_render_v));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (NULL);
	ww = ft_window_width(game_map);
	wh = ft_window_height(game_map);
	vars->win = mlx_new_window(vars->mlx, ww, wh, "sspina solong");
	ft_build_img(&game_map, &vars);
	ft_render_basic(game_map, &vars);
	ft_free_stuff(NULL, &vars);
	ft_free_stuff(&game_map, NULL);
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_hook(vars->win, 17, 0, exit_hook, &vars);
	mlx_loop_hook(vars->mlx, ft_pseudordm, &vars);
	mlx_loop(vars->mlx);
	key_hook(-1, &vars);
	return (vars);
}

t_render_v	*ft_start_render(t_game_map *game_map)
{
	t_render_v	*vars;

	vars = ft_init_window(game_map);
	return (vars);
}
