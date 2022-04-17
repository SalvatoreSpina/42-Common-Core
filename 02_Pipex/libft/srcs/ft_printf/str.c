/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:33 by sspina            #+#    #+#             */
/*   Updated: 2021/11/30 15:40:34 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	write_str(va_list *args)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	cnt = write(1, str, ft_strlen(str));
	return (cnt);
}
