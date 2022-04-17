/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:24 by sspina            #+#    #+#             */
/*   Updated: 2021/11/30 15:40:25 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_int(va_list *args)
{
	char	*num;
	int		tmp;
	int		cnt;

	tmp = va_arg(*args, int);
	num = ft_itoa(tmp);
	if (!num)
		return (0);
	cnt = write(1, num, ft_strlen(num));
	free(num);
	return (cnt);
}
