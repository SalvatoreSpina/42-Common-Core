/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:54:57 by achansel          #+#    #+#             */
/*   Updated: 2022/02/25 06:34:33 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	char	*dstcpy;

	dstcpy = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dstcpy);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;

	dst = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, (char *) s1);
	ft_strcpy(&dst[ft_strlen((char *) s1)], (char *) s2);
	return (dst);
}
