/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:41 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:45 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

void	put_tag(t_list *start, t_mem *mem)
{
	int	i;

	i = 0;
	while (start)
	{
		start->index = i++;
		start = start->next_sort;
	}
	mem->max = i;
}
