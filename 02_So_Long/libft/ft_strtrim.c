/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:42:33 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:47:19 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	l;
	int				start;
	int				end;
	char			*r;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	l = ft_strlen(s1);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	while (ft_inset(s1[start], set) == 1)
	{
		start++;
		l--;
	}
	while (ft_inset(s1[end - 1], set) == 1)
	{
		end--;
		l--;
	}
	r = ft_substr(s1, start, l);
	return (r);
}
