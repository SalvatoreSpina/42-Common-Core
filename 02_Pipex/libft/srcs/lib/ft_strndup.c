/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:42:51 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:39 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;

	if (n >= SIZE_MAX)
	{
		errno = ENOMEM;
		return (NULL);
	}
	dst = (char *)malloc(n + 1);
	if (!dst)
	{
		errno = ENOMEM;
		return (NULL);
	}
	dst = ft_memmove(dst, s1, n);
	dst[n] = '\0';
	return (dst);
}
