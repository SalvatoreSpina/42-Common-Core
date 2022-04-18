/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_libft2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:37:38 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:51:37 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	lists_swap(t_list **previous_next, t_list *last)
{
	t_list	*swap;

	swap = *previous_next;
	*previous_next = last->next_sort;
	swap->next_sort = last->next_sort->next_sort;
	(*previous_next)->next_sort = swap;
}

void	dirt_sorting(t_list **begin_list)
{
	t_list	*last;
	t_list	*prev;

	prev = NULL;
	last = *begin_list;
	while (last && last->next_sort)
	{
		if (last->value - last->next_sort->value > 0)
		{
			if (prev == NULL)
				lists_swap(begin_list, last);
			else
				lists_swap(&(prev->next_sort), last);
			last = *begin_list;
			prev = NULL;
		}
		else
		{
			prev = last;
			last = last->next_sort;
		}
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == 0)
			return (0);
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_putstr(char *str)
{
	int		i;
	char	n;

	i = 0;
	while (str[i])
		i++;
	n = '\n';
	write(1, str, i);
	write(1, &n, 1);
}

void	free_list(t_list **list)
{
	t_list	*l;
	t_list	*next;

	l = *list;
	while (l)
	{
		next = l->next;
		free(l);
		l = next;
	}
	*list = NULL;
}
