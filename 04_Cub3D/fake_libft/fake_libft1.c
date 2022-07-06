/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_libft1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:23:58 by sspina            #+#    #+#             */
/*   Updated: 2022/02/01 17:47:47 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Functions needed similiar to libft

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	size_t	i;
	size_t	needle_len;
	size_t	len;

	if (!*needle)
		return ((char *)haystack);
	hay = (char *)haystack;
	needle_len = ft_strlen(needle);
	len = ft_strlen(haystack);
	i = 0;
	while (*hay && i < len)
	{
		if (*hay == *needle && i + needle_len <= len)
			if (!ft_strncmp(hay, needle, needle_len))
				return (hay);
		hay++;
		i++;
	}
	return (NULL);
}

int	ft_inset(char *s1, char c)
{
	while (s1 && *s1)
	{
		if (c == *s1)
			return (1);
		s1++;
	}
	return (0);
}

int	ft_set_in_set(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (ft_inset(s2, s1[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	rows_counter(char **array)
{
	int	count;

	if (!array)
		return (0);
	count = 0;
	while (array[count])
		count++;
	return (count);
}

char	**free_bi_dimensional(char **array)
{
	int	index;

	index = rows_counter(array);
	while (index > 0)
	{
		free(array[index - 1]);
		index--;
	}
	free(array);
	return (NULL);
}
