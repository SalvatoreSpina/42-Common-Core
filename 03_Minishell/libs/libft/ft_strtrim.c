/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:51:53 by achansel          #+#    #+#             */
/*   Updated: 2022/03/18 14:01:14 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

static size_t	count_chars_to_trim(char *s1, char *charset, int op)
{
	int		i;
	size_t	count;

	if (!ft_strlen(s1))
		return (0);
	count = 0;
	i = 0;
	if (op == -1)
		i = ft_strlen(s1) - 1;
	while (s1[i] && i >= 0 && is_in(charset, s1[i]))
	{
		i += op;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	btrim;
	size_t	etrim;

	btrim = count_chars_to_trim((char *) s1, (char *) set, 1);
	etrim = count_chars_to_trim((char *) s1, (char *) set, -1);
	if (etrim == ft_strlen((char *) s1))
		return (ft_calloc(1, sizeof(char)));
	return (ft_strndup((char *) &s1[btrim],
			ft_strlen((char *) s1) - btrim - etrim));
}
