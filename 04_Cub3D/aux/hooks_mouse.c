/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 13:47:24 by sspina            #+#    #+#             */
/*   Updated: 2022/07/05 19:31:33 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_tab(t_everything *all)
{
	if (all->controller.mouse_grabbed)
	{
		all->controller.mouse_grabbed = 0;
		all->controller.first_input = 1;
		mlx_mouse_show();
	}
	return (0x5A550);
}

int	mouse_pressed(int button, int x, int y, t_everything *all)
{
	(void) x;
	(void) y;
	if (button == 1)
	{
		all->controller.mouse_grabbed = 1;
		mlx_mouse_hide();
	}
	return (0);
}

#ifndef SENSI
# define SENSI 0.025f
#endif

void	mouse_movement(int x, int y, t_everything *all)
{
	(void) y;
	if (all->controller.mouse_grabbed && all->controller.first_input)
	{
		if (x == 0 || x == 1919)
			all->controller.x = 800;
		else
			all->controller.x = x;
		all->controller.y = y;
		mlx_mouse_move(all->image.win, all->controller.x, all->controller.y);
		all->controller.first_input = 0;
	}
	else if (all->controller.mouse_grabbed && !all->controller.first_input)
	{
		if (x < all->controller.x)
		{
			all->ray.rot_left = (all->controller.x - x) * SENSI;
			all->ray.rot_right = 0.0f;
		}
		else if (x > all->controller.x)
		{
			all->ray.rot_right = (x - all->controller.x) * SENSI;
			all->ray.rot_left = 0.0f;
		}
		mlx_mouse_move(all->image.win, all->controller.x, all->controller.y);
	}
}
