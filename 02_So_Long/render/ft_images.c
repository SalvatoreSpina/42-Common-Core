/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:57:23 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:03 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_wall_image(t_render_v **vars, t_game_map **map)
{
	char		*wall;
	static void	*img;
	int			pos[2];

	wall = WALL;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	(*map)->wall = img;
}

void	ft_bottle_image(t_render_v **vars, t_game_map **map)
{
	char		*collec;
	static void	*img;
	int			pos[2];

	collec = BOTTLE;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, collec, &pos[0], &pos[1]);
	(*map)->collec = img;
}

void	ft_exit_image(t_render_v **vars, t_game_map **map)
{
	char		*exit;
	static void	*img;
	int			pos[2];

	exit = EXIT;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, exit, &pos[0], &pos[1]);
	(*map)->exit = img;
}

void	ft_bg_image(t_render_v **vars, t_game_map **map)
{
	char		*bg;
	static void	*img;
	int			pos[2];

	bg = FLOOR;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, bg, &pos[0], &pos[1]);
	(*map)->bg = img;
}
