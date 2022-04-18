/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:38:48 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:44 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorter.h"

int	main(int argc, char **argv)
{
	t_mem	mem;
	t_list	*start_tag;

	mem.a = NULL;
	mem.b = NULL;
	mem.print = 1;
	if (argc <= 1)
		return (0);
	arg_checking(argc, argv, &mem);
	if (!is_ordered(&mem))
	{
		start_tag = (mem.a);
		dirt_sorting(&start_tag);
		put_tag(start_tag, &mem);
		if (mem.max == 5)
			five_optimized(&mem);
		resolve(&mem, 1);
	}
	no_leaks_please(&mem);
	start_tag = NULL;
	return (0);
}
