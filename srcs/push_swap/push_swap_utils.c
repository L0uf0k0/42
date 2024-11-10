/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:48:18 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/10 14:31:17 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap(t_list **list, char l)
{
	int	temp;

	temp = *((*list)->data);
	*((*list)->data) = *((*list)->next->data);
	*((*list)->next->data) = temp;
	if(l == 'a')
		ft_putchar("sa\n");
	else
		ft_putchar("sb\n");
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
	if(l == 'a')
		ft_putchar("ra\n");
	else
		ft_putchar("rb\n");

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
	if(l == 'a')
		ft_putchar("rra\n");
	else
		ft_putchar("rrb\n");

}

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
	if(l == 'a')
		ft_putchar("pa\n");
	else
		ft_putchar("pb\n");
}

faire les rrr rr et ss enfin les doubles quoi
