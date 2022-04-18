/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:17:09 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:37 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bchar;

	i = 0;
	bchar = (unsigned char *)b;
	while (i < len)
	{
		bchar[i] = c;
		i++;
	}
	return (b = bchar);
}
