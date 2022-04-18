/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:44:35 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:49:30 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_numberlength(unsigned int n)
{
	unsigned int	o;
	unsigned int	l;

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

int	ft_putuint(unsigned int n)
{
	ft_putunbr_fd(n, 1);
	if (n == 0)
		return (1);
	return (ft_numberlength(n));
}
