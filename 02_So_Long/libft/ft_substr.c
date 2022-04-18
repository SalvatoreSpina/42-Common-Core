/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:42:46 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:57 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*d;
	unsigned int	c;

	c = 0;
	d = (char *) malloc(sizeof(char) * (len + 1));
	if (!d || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (d);
	while (c < len)
	{
		d[c] = s[c + start];
		c++;
	}
	d[c] = '\0';
	return (d);
}
