/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:46:20 by achansel          #+#    #+#             */
/*   Updated: 2021/10/23 14:09:46 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		cur;

	i = 0;
	cur = 0;
	if (*needle == '\0')
		return ((char *) haystack);
	while (haystack[i + cur] && i + cur < len)
	{
		if (haystack[i + cur] == needle[cur])
		{
			cur++;
			if (!needle[cur])
				return ((char *) &haystack[i]);
		}
		else
		{
			cur = 0;
			i++;
		}
	}
	return (NULL);
}
