/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:32:50 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:53 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	arg_checking(int argc, char **argv, t_mem *mem)
{
	int	j;
	int	i;
	int	can_space;

	i = 1;
	can_space = 1;
	while (i < argc)
	{
		can_space = 1;
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '+' && argv[i][j] != '-' && argv[i][j] != ' '
				&& !ft_isdigit(argv[i][j]))
				exit_error(mem);
			if (can_space == 1 && argv[i][j] != ' ')
			{
				fill_a(&(mem->a), ft_atoi(argv[i] + j, mem), -1, mem);
				can_space = 0;
			}
			can_space = argv[i][j] == ' ';
		}
		i++;
	}
}
