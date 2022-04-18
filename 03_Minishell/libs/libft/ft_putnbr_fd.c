/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:35:06 by achansel          #+#    #+#             */
/*   Updated: 2021/10/19 10:39:52 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define MAX_INT_REPRESENTATION_LENGTH 34

static unsigned int	absolute(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	return (n);
}

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
}

static int	convert_num_to_string(int n, char *buf)
{
	unsigned int	num;
	int				curr;

	num = absolute(n);
	curr = 0;
	while (num)
	{
		buf[curr++] = (num % 10) + 48;
		num /= 10;
	}
	if (curr == 0)
		buf[curr++] = 0 + 48;
	if (n < 0)
		buf[curr++] = '-';
	reverse_string(buf, curr);
	return (curr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num_as_str[MAX_INT_REPRESENTATION_LENGTH];
	int		l;

	l = convert_num_to_string(n, num_as_str);
	write(fd, num_as_str, l);
}
