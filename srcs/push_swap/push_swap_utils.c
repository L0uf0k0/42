/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:48:18 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/09 23:40:56 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_list **list)
{
	int	temp;

	temp = *((*list)->data);
	*((*list)->data) = *((*list)->next->data);
	*((*list)->next->data) = temp;
}

void	ft_rotate(t_list **list)
{
	t_list	*temp;

	temp = (*list);
	while (temp->next)
	{
		ft_swap(&temp);
		temp = temp->next;
	}
}

void	ft_rev_rotate(t_list **list)
{
	t_list	*temp;

	temp = ft_lstlast(*list);
	temp = temp->prev;
	while (temp)
	{
		ft_swap(&temp);
		temp = temp->prev;
	}
}
#include <unistd.h>
void	ft_push(t_list **lst1, t_list **lst2)
{
	if (!*lst2)
	{
		*lst2 = *lst1;
		*lst1 = (*lst1)->next;
		(*lst1)->prev = NULL;
		(*lst2)->next = NULL;
		return ;
	}
	(*lst2)->prev = *lst1;
	*lst1 = (*lst1)->next;
	(*lst1)->prev = NULL;
	(*lst2)->prev->next = (*lst2);
	*lst2 = (*lst2)->prev;

}
