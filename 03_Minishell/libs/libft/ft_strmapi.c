/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:23:52 by achansel          #+#    #+#             */
/*   Updated: 2021/10/19 12:26:28 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;
	int		length;

	length = ft_strlen((char *) s);
	i = 0;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);
	while (i < length)
	{
		ret[i] = f(i, (char) s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
