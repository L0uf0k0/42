/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:52:03 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/01 04:15:45 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_list *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	push_back_cond(t_list **lst, t_list **node)
{
	if (!*node)
		return (0);
	if ((*node)->data < (*lst)->data && (*node)->data > ft_lstlast(*lst)->data
		&& (*lst)->data > ft_lstlast(*lst)->data)
		return (1);
	else if ((*node)->data > ft_max(*lst)
		&& ft_lstlast(*lst)->data == ft_max(*lst))
		return (1);
	else if ((*node)->data < ft_min(*lst) && (*lst)->data == ft_min(*lst))
		return (1);
	else
		return (0);
}

void	push_back(t_list **lst1, t_list **lst2, int size)
{
	while (!checker(lst1, lst2, size))
	{
		if (push_back_cond(lst1, lst2))
			ft_push(lst2, lst1, 'a');
		else
			ft_rotate(lst1, 'a');
	}
}

void	process(t_list **lst1, t_list **lst2)
{
	int	size;

	size = ft_lstsize(*lst1);
	if (size == 2 && !checker(lst1, lst2, size))
		ft_swap(lst1, 'a');
	else if (size == 3)
		sort3(lst1);
	else if (size == 4)
		sort4(lst1, lst2);
	else if (size == 5)
		sort5(lst1, lst2, size);
	if (size < 10 && !checker(lst1, lst2, size))
		force_sort(lst1, lst2);
	else
	{
		ft_push(lst1, lst2, 'b');
		ft_push(lst1, lst2, 'b');
		while(!checker(lst1, lst2, size))
			calcul(lst1, lst2, size);
	}
	if (PRINT)
		show_list(lst1, lst2);
}
