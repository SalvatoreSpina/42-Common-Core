/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:11:49 by achansel          #+#    #+#             */
/*   Updated: 2021/10/24 13:08:48 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define MAX_INT_REPRESENTATION_LENGTH 34

static void	reverse_string(char *str, int len)
{
	int		begin;
	int		end;
	char	tmp;

	begin = 0;
	end = len - 1;
	while (begin < end)
	{
		tmp = str[begin];
		str[begin++] = str[end];
		str[end--] = tmp;
	}
	str[len] = '\0';
}

static int	get_length_as_str(int n)
{
	int				l;
	unsigned int	bob;

	l = 0;
	bob = n;
	if (!n)
		return (1);
	if (n < 0)
	{
		l++;
		bob = -n;
	}
	while (bob)
	{
		bob /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char			*num_as_str;
	unsigned int	num;
	int				curr;

	num_as_str = malloc(get_length_as_str(n) + 1);
	if (!num_as_str)
		return (NULL);
	num = n;
	if (n < 0)
		num = -n;
	curr = 0;
	while (num)
	{
		num_as_str[curr++] = (num % 10) + 48;
		num /= 10;
	}
	if (!n)
		num_as_str[curr++] = '0';
	if (n < 0)
		num_as_str[curr++] = '-';
	reverse_string(num_as_str, curr);
	return (num_as_str);
}
