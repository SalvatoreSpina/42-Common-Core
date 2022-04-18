/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:33:31 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:30 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_if_putenemy(t_game_map **map)
{
	if (BONUS == 1)
		ft_put_enemy(map);
}

void	ft_put_steps(t_render_v **vars, t_game_map **map)
{
	char	*go;

	if (BONUS)
	{
		go = ft_itoa((*map)->steps);
		mlx_string_put((*vars)->mlx, (*vars)->win, 10, 10, RED, go);
		free(go);
	}
}
