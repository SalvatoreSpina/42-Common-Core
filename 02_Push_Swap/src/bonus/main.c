/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:30:46 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:58 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_mem	mem;

	mem.a = NULL;
	mem.b = NULL;
	mem.print = 0;
	if (argc <= 1)
		return (0);
	arg_checking(argc, argv, &mem);
	read_instructions(&mem);
	if (is_ordered(&mem))
		ft_putstr("OK");
	else
		ft_putstr("KO");
	no_leaks_please(&mem);
	return (0);
}
