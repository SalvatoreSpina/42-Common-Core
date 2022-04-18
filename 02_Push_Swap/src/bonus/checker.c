/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:29:41 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:54 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_instructions(t_mem *mem)
{
	char	instruction[4];
	int		index;
	int		prev_index;

	index = 0;
	while (index < 4)
	{
		prev_index = index;
		index += read(0, instruction + index, 1);
		if (prev_index == index)
			break ;
		if (instruction[prev_index] == '\n')
		{
			instruction[prev_index] = 0;
			if (!execute_action(instruction, mem))
				exit_error(mem);
			index = 0;
		}
	}
	if (index == 4)
		exit_error(mem);
}

int	execute_action(char *name, t_mem *mem)
{
	if (!ft_strcmp(name, "sa"))
		swap_a(mem);
	else if (!ft_strcmp(name, "sb"))
		swap_b(mem);
	else if (!ft_strcmp(name, "ss"))
		swap_a_b(mem);
	else if (!ft_strcmp(name, "pa"))
		push_a(mem);
	else if (!ft_strcmp(name, "pb"))
		push_b(mem);
	else if (!ft_strcmp(name, "ra"))
		rotate_a(mem);
	else if (!ft_strcmp(name, "rb"))
		rotate_b(mem);
	else if (!ft_strcmp(name, "rr"))
		rotate_a_b(mem);
	else if (!ft_strcmp(name, "rra"))
		rev_rotate_a(mem);
	else if (!ft_strcmp(name, "rrb"))
		rev_rotate_b(mem);
	else if (!ft_strcmp(name, "rrr"))
		rev_rotate_a_b(mem);
	else
		return (0);
	return (1);
}
