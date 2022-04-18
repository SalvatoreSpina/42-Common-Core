/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:16:31 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:46 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howmanydigit(long n)
{
	size_t	howmanydigit;
	int		flagneg;

	howmanydigit = 0;
	flagneg = 0;
	if (n < 0)
	{
		howmanydigit++;
		flagneg++;
		n = -n;
	}
	while (n >= 1)
	{
		howmanydigit++;
		n /= 10;
	}
	return (howmanydigit);
}

static char	*ft_gen(char *retur, long nbr, int len, int flagneg)
{
	if (nbr != 0)
		retur = malloc(sizeof(char) * (len + 1));
	else
		return (retur = ft_strdup("0"));
	if (!retur)
		return (0);
	flagneg = 0;
	if (nbr < 0)
	{
		flagneg++;
		nbr = -nbr;
	}
	retur[len] = '\0';
	while (--len)
	{
		retur[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (flagneg == 1)
		retur[0] = '-';
	else
		retur[0] = (nbr % 10) + '0';
	return (retur);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*retur;
	long	nbr;
	int		flagneg;

	nbr = n;
	len = ft_howmanydigit(nbr);
	retur = 0;
	flagneg = 0;
	retur = ft_gen(retur, nbr, len, flagneg);
	if (!(retur))
		return (0);
	return (retur);
}
