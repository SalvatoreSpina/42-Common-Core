/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:04:03 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:02 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_trainer_img(t_render_v **vars, t_game_map **map)
{
	char		*trainer;
	static void	*img;
	int			pos[2];

	trainer = "./assets/one.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, trainer, &pos[0], &pos[1]);
	(*map)->trainer = img;
}

void	ft_trainer2_img(t_render_v **vars, t_game_map **map)
{
	char		*trainer;
	static void	*img;
	int			pos[2];

	trainer = "./assets/two.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, trainer, &pos[0], &pos[1]);
	(*map)->trainer = img;
}

void	ft_trainer3_img(t_render_v **vars, t_game_map **map)
{
	char		*trainer;
	static void	*img;
	int			pos[2];

	trainer = "./assets/three.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, trainer, &pos[0], &pos[1]);
	(*map)->trainer = img;
}

void	ft_trainer4_img(t_render_v **vars, t_game_map **map)
{
	char		*trainer;
	static void	*img;
	int			pos[2];

	trainer = "./assets/four.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, trainer, &pos[0], &pos[1]);
	(*map)->trainer = img;
}
