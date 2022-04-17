/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:33:00 by sspina            #+#    #+#             */
/*   Updated: 2022/01/03 17:33:01 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	no_leaks_please(t_mem *mem)
{
	free_list(&(mem->a));
	free_list(&(mem->b));
}

void	exit_error(t_mem *mem)
{
	ft_puterr("Error");
	no_leaks_please(mem);
	exit(EXIT_FAILURE);
}
