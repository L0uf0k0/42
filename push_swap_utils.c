/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:48:18 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/01 16:00:07 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **list, int l)
{
	t_list *first;
	t_list *second;

	if (!list || !(*list) || !((*list)->next)) // Vérifie si l'échange est possible
		return;
	first = *list;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*list = second;
	if (l == 'a')
		ft_putstr("sa\n");
	else if (l == 'b')
		ft_putstr("sb\n");
}

void	ft_rotate(t_list **list, int l)
{
	t_list *first;
	t_list *last;

	if (!list || !(*list) || !((*list)->next))
		return;
	first = *list;
	last = ft_lstlast(*list);
	*list = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (l == 'a')
		ft_putstr("ra\n");
	else if (l == 'b')
		ft_putstr("rb\n");
}

void	ft_rev_rotate(t_list **list, int l)
{
	t_list *last;

	if (!list || !(*list) || !((*list)->next))
		return;
	last = ft_lstlast(*list);
	last->prev->next = NULL;
	last->next = *list;
	(*list)->prev = last;
	*list = last;
	if (l == 'a')
		ft_putstr("rra\n");
	else if (l == 'b')
		ft_putstr("rrb\n");
}


/*
void	ft_rev_rotate(t_list **list, int l)
{
	t_list	*temp;

	temp = ft_lstlast(*list);
	temp = temp->prev;
	while (temp)
	{
		ft_swap(&temp, 'c');
		temp = temp->prev;
	}
	if (l == 'a')
		ft_putstr("rra\n");
	else if (l == 'b')
		ft_putstr("rrb\n");
}
*/
void	ft_push(t_list **lst1, t_list **lst2, int l)
{
	if (!*lst2 && *lst1)
	{
		*lst2 = *lst1;
		*lst1 = (*lst1)->next;
		(*lst1)->prev = NULL;
		(*lst2)->next = NULL;
	}
	else if (*lst2 && *lst1)
	{
		(*lst2)->prev = *lst1;
		if ((*lst1)->next)
		{
			*lst1 = (*lst1)->next;
			(*lst1)->prev = NULL;
		}
		else
			*lst1 = NULL;
		(*lst2)->prev->next = (*lst2);
		*lst2 = (*lst2)->prev;
	}
	if (l == 'a')
		ft_putstr("pa\n");
	else if (l == 'b')
		ft_putstr("pb\n");
}
