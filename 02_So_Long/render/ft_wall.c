/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:06:41 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_wall1(t_render_v **vars, t_game_map **map)
{
	char		*wall;
	static void	*img;
	int			pos[2];

	wall = WALL;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	(*map)->wall = img;
}

void	ft_wall2(t_render_v **vars, t_game_map **map)
{
	char		*wall;
	static void	*img;
	int			pos[2];

	wall = WALL2;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	(*map)->wall = img;
}

void	ft_wall3(t_render_v **vars, t_game_map **map)
{
	char		*wall;
	static void	*img;
	int			pos[2];

	wall = WALL3;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	(*map)->wall = img;
}
