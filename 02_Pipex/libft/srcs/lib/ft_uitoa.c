/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:42:28 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:52:15 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	int64_t	nn;
	size_t	len;
	char	*dst;

	nn = n;
	len = ft_numlen(nn);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	if (nn == 0)
		dst[0] = '0';
	dst[len--] = '\0';
	while (nn > 0)
	{
		dst[len--] = nn % 10 + '0';
		nn /= 10;
	}
	return (dst);
}
