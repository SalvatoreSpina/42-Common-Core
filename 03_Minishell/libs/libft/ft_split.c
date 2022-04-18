/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:01:18 by achansel          #+#    #+#             */
/*   Updated: 2021/10/25 16:28:19 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	**push_into_charpp_array(char **arr, int arr_sz, char *newstr)
{
	char	**newarr;
	int		i;

	newarr = malloc((arr_sz + 2) * sizeof(char *));
	if (!newarr)
		return (NULL);
	i = 0;
	while (i < arr_sz)
	{
		newarr[i] = arr[i];
		i++;
	}
	newarr[i++] = newstr;
	newarr[i] = 0;
	if (arr)
		free(arr);
	return (newarr);
}

static int	set_word_and_reset_counter(char **cw, const char *str)
{
	*cw = (char *) str;
	return (0);
}

char	**ft_split(const char *str, char delim)
{
	char	**words;
	int		wsz;
	char	*cw;
	int		cwl;

	wsz = 0;
	cwl = 0;
	cw = 0;
	words = push_into_charpp_array(0, wsz, 0);
	while (*str)
	{
		if (*str != delim && !cw)
			cwl = set_word_and_reset_counter(&cw, str);
		if (*str == delim && cw)
		{
			words = push_into_charpp_array(words, wsz++, ft_strndup(cw, cwl));
			cw = 0;
		}
		cwl++;
		str++;
	}
	if (cw)
		words = push_into_charpp_array(words, wsz++, ft_strndup(cw, cwl));
	return (words);
}
