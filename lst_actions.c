/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:19:52 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 22:22:23 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*ft_lstnew(int data)
{
	t_l	*new;

	new = (t_l *)calloc(1, sizeof(t_l));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	new->cost = 0;
	new->sens = 11;
	return (new);
}

t_l	*ft_lstlast(t_l *lst)
{
	t_l	*last;

	last = lst;
	if (!last)
		return (last);
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

void	ft_lstclear(t_l **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, (*del));
	del(&(*lst)->data);
	free(*lst);
	*lst = NULL;
}

int	ft_lstsize(t_l *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		count += 1;
		lst = lst->next;
	}
	return (count);
}
