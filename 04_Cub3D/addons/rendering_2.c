/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:32:55 by achansel          #+#    #+#             */
/*   Updated: 2022/07/05 21:02:48 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda_bonus(t_everything *all, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (all->info.map[ray->map_x][ray->map_y] == '1'
			OR all->info.map[ray->map_x][ray->map_y] == 'C')
			ray->hit = 1;
	}
}

void	perform_adequate_drawings(t_everything *all, t_ray *ray, int x)
{
	if (ray->side == 1 && ray->step_y == 1)
		draw_tex(all, ray, all->tex.w_img, x);
	else if (ray->side == 1 AND ray->step_y == -1)
		draw_tex(all, ray, all->tex.e_img, x);
	else if (ray->side == 0 && ray->step_x == 1)
		draw_tex(all, ray, all->tex.n_img, x);
	else if (ray->side == 0 && ray->step_x == -1)
		draw_tex(all, ray, all->tex.s_img, x);
}
