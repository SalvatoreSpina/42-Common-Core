/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:18 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*g;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *) s;
	while (n > i)
	{
		if ((d[i] != (unsigned char)c))
			i++;
		else
		{
			g = (unsigned char *) &s[i];
			return (g);
		}
	}
	return (0);
}
