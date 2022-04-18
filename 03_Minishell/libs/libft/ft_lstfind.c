/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 10:20:00 by achansel          #+#    #+#             */
/*   Updated: 2022/02/01 17:20:18 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int (*cmp)(void *, void *), void *rhs)
{
	while (lst)
	{
		if (!cmp(lst->content, rhs))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
