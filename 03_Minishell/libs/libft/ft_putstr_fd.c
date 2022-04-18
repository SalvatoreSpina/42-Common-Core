/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:30:50 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:32:13 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

// printf sur le fd2
int	fsf(char *s, ...)
{
	va_list	l;
	int		count;

	va_start(l, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && *(++s) == 's')
		{
			count += ft_putstr_fd(va_arg(l, char *), 2);
			s++;
		}
		else
			count += write(2, s++, 1);
	}
	va_end(l);
	return (count);
}

int	ft_putstr_fd(char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
