/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:44:20 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:48:13 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_numberlength(int n)
{
	unsigned int	o;
	int				l;

	l = 0;
	if (n < 0)
	{
		o = -n;
	}
	else
	{
		o = n;
	}
	while (o > 0)
	{
		o /= 10;
		l++;
	}
	return (l);
}

int	ft_putint(int n)
{
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	if (n < 0)
		return (ft_numberlength(n) + 1);
	return (ft_numberlength(n));
}
