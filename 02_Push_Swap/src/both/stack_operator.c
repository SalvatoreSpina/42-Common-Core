/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sspina <sspina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:32:55 by sspina            #+#    #+#             */
/*   Updated: 2022/04/18 09:46:54 by sspina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	fill_a(t_list **stack, int value, int tag, t_mem *mem)
{
	t_list	*elem;
	t_list	*last;

	last = *stack;
	if (list_contains_value(*stack, value))
		exit_error(mem);
	elem = malloc(sizeof(t_list));
	if (!elem)
		exit_error(mem);
	elem->next = NULL;
	elem->next_sort = NULL;
	elem->value = value;
	elem->index = tag;
	if (last == NULL)
	{
		*stack = elem;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = elem;
	last->next_sort = elem;
}

void	swap(t_list **stack)
{
	t_list	*temp;
	t_list	*third;

	if (!*stack || !(*stack)->next)
		return ;
	third = (*stack)->next->next;
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = temp;
	temp->next = third;
}

void	push_top(t_list **x1, t_list **x2)
{
	t_list	*top;

	if (!*x1)
		return ;
	top = *x1;
	*x1 = top->next;
	if (*x2)
		top->next = (*x2);
	else
		top->next = NULL;
	*x2 = top;
}

void	push_top_to_bot(t_list **x)
{
	t_list	*top;
	t_list	*temp;

	if (!*x || !(*x)->next)
		return ;
	top = *x;
	*x = (*x)->next;
	temp = *x;
	while (temp->next)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
}

void	push_bot_to_top(t_list **x)
{
	t_list	*last;
	t_list	*prev;

	if (!*x || !(*x)->next)
		return ;
	last = *x;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = (*x);
	*x = last;
	prev->next = NULL;
}
