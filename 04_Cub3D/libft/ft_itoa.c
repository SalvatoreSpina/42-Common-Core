/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:16:31 by sspina            #+#    #+#             */
/*   Updated: 2022/06/13 11:10:34 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(char *buf, int n)
{
	unsigned int	num;
	int				curr;

	num = n;
	if (n < 0)
		num = -n;
	curr = 0;
	while (num)
	{
		buf[curr++] = (num % 10) + 48;
		num /= 10;
	}
	if (!n)
		buf[curr++] = '0';
	if (n < 0)
		buf[curr++] = '-';
	reverse_string(buf, curr);
	return (buf);
}
