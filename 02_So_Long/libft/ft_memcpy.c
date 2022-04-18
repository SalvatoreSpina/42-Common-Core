/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:31 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:33 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	e;
	unsigned char	*d;
	unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	e = 0;
	while (n > e)
	{
		d[e] = s[e];
		e++;
	}
	return (dst);
}
