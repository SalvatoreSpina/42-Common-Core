/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:56:01 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:01 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointernumber(char const *s, char c)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] && s[i - 1] == c)
			nbr++;
		if (s[i])
			i++;
	}
	if (s[0] != c && s[0] != '\0')
		nbr++;
	if (nbr == 0 && s[i - 1] == c)
		return (0);
	return (nbr);
}

char	**ft_mallocher(char **strs, char const *s, char c)
{
	size_t	count;
	int		i;
	int		h;

	count = 0;
	i = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c)
			count++;
		else if (h > 0 && s[h - 1] != c)
		{
			strs[i] = malloc(sizeof(char) * (count + 1));
			if (!*(strs + i++))
				return (0);
			count = 0;
		}
		if (s[h + 1] == '\0' && s[h] != c)
			strs[i] = ft_calloc((count + 1), sizeof(char));
		if (!(strs))
			return (0);
		h++;
	}
	return (strs);
}

char	**ft_cpy(char **strs, char const *s, char c)
{
	int	i;
	int	j;
	int	h;

	i = 0;
	j = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c)
			strs[i][j++] = s[h];
		else if (h > 0 && s[h - 1] != c)
		{
			if (h != 0)
			{
				strs[i][j] = '\0';
				j = 0;
				i++;
			}
			if (s[h + 1] == '\0' && s[h] != c)
				strs[i][j] = '\0';
		}
		h++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		pointernumber;

	if (!s)
		return (NULL);
	pointernumber = ft_pointernumber(s, c);
	splitted = ft_calloc((pointernumber + 1), sizeof(char *));
	if (!splitted)
		return (0);
	if (ft_mallocher(splitted, s, c) != 0)
		ft_cpy(splitted, s, c);
	else
	{
		free(splitted);
		return (NULL);
	}
	splitted[pointernumber] = (void *)0;
	return (splitted);
}
