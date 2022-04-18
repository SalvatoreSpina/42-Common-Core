/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:00:01 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:10 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)(str + i));
		else
			i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;

	len = ft_strlen(str) + 1;
	dup = malloc(len * sizeof(char));
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = str[len];
	return (dup);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!str)
		return (NULL);
	if ((size_t)ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	if (start > (size_t)ft_strlen(str))
		return (ft_strdup(""));
	sub = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!sub)
		return (NULL);
	while ((size_t)i < len)
	{
		sub[i] = *(str + start + i);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*join;
	int		total_length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_length = ft_strlen(str1) + ft_strlen(str2) + 1;
	join = malloc(total_length * sizeof(char));
	if (!join)
		return (NULL);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		join[i + j] = str2[j];
		j++;
	}
	join[total_length - 1] = '\0';
	return (join);
}
