/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:24:48 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:30 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	state1(t_game_map **m, t_render_v **v)
{
	ft_trainer_img(v, m);
}

static void	state2(t_game_map **m, t_render_v **v)
{
	ft_trainer2_img(v, m);
}

static void	state3(t_game_map **m, t_render_v **v)
{
	ft_trainer3_img(v, m);
}

static void	state4(t_game_map **m, t_render_v **v)
{
	ft_trainer4_img(v, m);
}

int	ft_animate(t_game_map **m, t_render_v **v)
{
	static int			loop = 0;
	static t_render_v	**vars;

	if (BONUS)
	{
		if (v)
			vars = v;
		loop++;
		if (loop == 0 && (vars && m))
			state1(m, vars);
		if (loop == 1 && (vars && m))
			state2(m, vars);
		if (loop == 2 && (vars && m))
			state3(m, vars);
		if (loop == 3 && (vars && m))
			state4(m, vars);
		if (loop == 4 && m && vars)
			loop = 0;
	}
	return (1);
}
