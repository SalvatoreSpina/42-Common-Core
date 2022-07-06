/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:47:24 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 20:00:34 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Close windows and free

int	destroy_window(t_everything *all)
{
	free_bi_dimensional(all->info.map);
	mlx_destroy_window(all->image.mlx, all->image.win);
	success_msg("Goodbye (:");
	exit(0);
	return (1);
}

// Move and render image

int	key_pressed(int keycode, t_everything *all)
{
	if (keycode == ESC)
		destroy_window(all);
	if (keycode == TAB)
		handle_tab(all);
	else if (keycode == FORWARD)
		all->ray.forward = 1;
	else if (keycode == BACKWARDS)
		all->ray.backwards = 1;
	else if (keycode == LEFT)
		all->ray.left = 1;
	else if (keycode == RIGHT)
		all->ray.right = 1;
	else if (keycode == RROTATE)
		all->ray.rot_right = 1;
	else if (keycode == LROTATE)
		all->ray.rot_left = 1;
	else if (keycode == OPEN)
		all->ray.open_door = 1;
	return (keycode);
}

// Stops and render image

int	key_released(int keycode, t_everything *all)
{
	if (keycode == FORWARD)
		all->ray.forward = 0;
	else if (keycode == BACKWARDS)
		all->ray.backwards = 0;
	else if (keycode == LEFT)
		all->ray.left = 0;
	else if (keycode == RIGHT)
		all->ray.right = 0;
	else if (keycode == RROTATE)
		all->ray.rot_right = 0;
	else if (keycode == LROTATE)
		all->ray.rot_left = 0;
	else if (keycode == OPEN)
		all->ray.open_door = 0;
	return (keycode);
}
