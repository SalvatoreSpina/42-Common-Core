/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:28:16 by achansel          #+#    #+#             */
/*   Updated: 2022/04/09 18:32:28 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdelone_ptr(t_list **head, t_list *node, void (*del)(void*))
{
	t_list	*curr;
	t_list	*prev;
	t_list	*save;

	curr = NULL;
	if (*head)
		curr = (*head)->next;
	prev = *head;
	while (curr != node && curr != NULL)
	{
		if (prev)
			prev = prev->next;
		curr = curr->next;
	}
	if (node == *head)
		*head = node->next;
	else if (curr != NULL && node != *head)
		prev->next = node->next;
	save = node->next;
	ft_lstdelone(node, del);
	return (save);
}
