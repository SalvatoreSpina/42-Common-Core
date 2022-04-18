/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:05 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:26 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*d;
	unsigned int	size;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1;
	d = malloc(sizeof(char) * (size));
	if (!d)
		return (0);
	ft_memcpy(d, (const void *) s1, ft_strlen((char *) s1));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	ft_memcpy(&d[ft_strlen((char *) s1)], s2, ft_strlen((char *) s2));
	ft_memcpy(&d[size - 1], "\0", 1);
	return (d);
}
