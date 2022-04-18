/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansel <achansel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:14:51 by achansel          #+#    #+#             */
/*   Updated: 2022/02/01 17:15:52 by achansel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*curr;

	curr = *alst;
	if (!curr)
	{
		*alst = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
