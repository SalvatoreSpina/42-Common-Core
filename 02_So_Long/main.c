/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:48:21 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:13 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_stuff(t_game_map **game_map, t_render_v **vars)
{
	static t_game_map	**game_mapm;
	static t_render_v	**varsm;
	int					maph;

	if (game_mapm && varsm && (!game_map && !vars))
	{
		maph = (*game_mapm)->map_height;
		ft_free_map_data(&((*game_mapm)->map_data), maph);
		free((*game_mapm));
		free((*varsm));
		game_mapm = NULL;
		varsm = NULL;
	}
	if (game_map)
		game_mapm = game_map;
	if (vars)
		varsm = vars;
}

static int	ft_exit_with_error(void)
{
	ft_putendl_fd("Error", 2);
	ft_putstr("The map is invalid or the file was not found.");
	ft_putstr("Also, check the file ending.");
	return (1);
}

int	ft_start_game(t_game_map *game_map)
{
	ft_start_render(game_map);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_map	*game_map;

	if (!ft_get_map(argc, argv, &game_map))
	{
		ft_exit_with_error();
		return (0);
	}
	ft_free_stuff(&game_map, NULL);
	if (!game_map)
		return (ft_exit_with_error());
	game_map->game_score = 0;
	game_map->game_over = 0;
	game_map->draw_p = 0;
	game_map->steps = 0;
	ft_pseudordm();
	ft_control_player(-1, game_map);
	ft_start_game(game_map);
	return (0);
}
