/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:44:00 by sspina            #+#    #+#             */
/*   Updated: 2021/11/30 15:44:02 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recur_putnbr_base(size_t n, char *base, size_t baselen, int *cnt)
{
	if (n >= baselen)
		ft_recur_putnbr_base(n / baselen, base, baselen, cnt);
	*cnt += write(1, &base[n % baselen], 1);
}

int	ft_putnbr_base(size_t n, char *base)
{
	size_t	baselen;
	int		cnt;

	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	cnt = 0;
	ft_recur_putnbr_base(n, base, baselen, &cnt);
	return (cnt);
}
