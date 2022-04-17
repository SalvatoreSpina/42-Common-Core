/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:17:09 by sspina            #+#    #+#             */
/*   Updated: 2021/10/27 15:28:55 by sspina           ###   ########.fr       */
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
