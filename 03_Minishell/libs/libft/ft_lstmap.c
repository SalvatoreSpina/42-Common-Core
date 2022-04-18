/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:15:43 by achansel          #+#    #+#             */
/*   Updated: 2021/10/26 17:13:02 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head_new;
	t_list	*curr_new;

	(void) del;
	head_new = ft_lstnew(f(lst->content));
	if (!head_new)
		return (NULL);
	lst = lst->next;
	curr_new = head_new;
	while (lst)
	{
		curr_new->next = ft_lstnew(f(lst->content));
		if (!curr_new->next)
			return (NULL);
		curr_new = curr_new->next;
		lst = lst->next;
	}
	return (head_new);
}
