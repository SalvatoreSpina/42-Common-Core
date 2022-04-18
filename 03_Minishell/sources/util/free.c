/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:32:20 by achansel          #+#    #+#             */
/*   Updated: 2022/04/08 19:26:21 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_mult(int count, void **addrs)
{
	int	i;

	i = 0;
	while (i < count)
		free(addrs[i++]);
}

void	free_2d(void **a)
{
	int					idx;
	unsigned long long	**arr;

	idx = 0;
	arr = (unsigned long long **) a;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}
