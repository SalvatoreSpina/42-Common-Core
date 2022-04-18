/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:38:38 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:19 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	e;

	e = 0;
	if (dst == 0 && src == 0)
		return (NULL);
	if (dst > src)
	{
		while (len > e)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		while (e < len)
		{
			((char *)dst)[e] = ((char *)src)[e];
			e++;
		}
	}
	return (dst);
}
