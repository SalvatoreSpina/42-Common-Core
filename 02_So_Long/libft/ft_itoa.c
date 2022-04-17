/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:36:33 by sspina            #+#    #+#             */
/*   Updated: 2021/11/18 14:36:35 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numberlength(int n)
{
	int	o;
	int	l;

	o = n;
	l = 0;
	if (n < 0)
		o = -o;
	while (o > 0)
	{
		o /= 10;
		l++;
	}
	return (l);
}

void	ft_complete_string(char *str, int neg, int n)
{
	if (neg == 1)
		str[0] = '-';
	str[ft_numberlength(n) + neg] = '\0';
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	int		length;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	length = ft_numberlength(n);
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	str = (char *)malloc((sizeof(char) * ft_numberlength(n)) + 1 + neg);
	if (!str)
		return (0);
	ft_complete_string(str, neg, n);
	while (length--)
	{
		str[length + neg] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
