/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:52:03 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/17 01:19:41 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	checker(t_list **lst1, t_list **lst2, int size)
{
	t_list	*lst;
	int		temp;

	if (ft_lstsize(*lst1) != size || ft_lstsize(*lst2) > 0)
		return (0);
	lst = *lst1;
	while (lst->next)
	{
		temp = lst->data;
		lst = lst->next;
		if (lst->data < temp)
			return (0);
	}
	return (1);
}

void	sort3(t_list **lst1)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = (*lst1)->data;
	temp2 = (*lst1)->next->data;
	temp3 = (*lst1)->next->next->data;

	if (temp1 < temp2 && temp2 < temp3)
		return;
	if (temp1 < temp2 && temp1 < temp3)
	{
		ft_swap(lst1, 'a');
		ft_rotate(lst1, 'a');
	}
	else if (temp1 > temp2 && temp1 < temp3)
		ft_swap(lst1, 'a');
	else if (temp1 < temp2 && temp1 > temp3)
		ft_rev_rotate(lst1, 'a');
	else if (temp1 > temp2 && temp2 < temp3)
		ft_rotate(lst1, 'a');
	else if (temp1 > temp2 && temp2 > temp3)
	{
		ft_swap(lst1, 'a');
		ft_rev_rotate(lst1, 'a');
	}
}

void	push_back(t_list **lst1, t_list **lst2)
{
	while (!checker(lst1, lst2, ft_lstsize(*lst1) + ft_lstsize(*lst2)))
	{
		if (*lst2 && (*lst2)->data < (*lst1)->data && (*lst2)->data > ft_lstlast(*lst1)->data)
			ft_push(lst2, lst1, 'a');
		else
			ft_rotate(lst1, 'a');
	}
}

void	sort4(t_list **lst1, t_list **lst2)
{
	ft_push(lst1, lst2, 'b');
	sort3(lst1);
	push_back(lst1, lst2);
}

void	process(t_list **lst1, t_list **lst2)
{
	int	size;

	size = ft_lstsize(*lst1);
	if (size == 2 && !checker(lst1, lst2, size))
		ft_swap(lst1, 'a');
	if (size == 3)
		sort3(lst1);
	if (size == 4 && !checker(lst1, lst2, size))
		sort4(lst1, lst2);
	while (!checker(lst1, lst2, size))
	{
		calcul(lst1, lst2);
	}
	show_list(lst1, lst2);
	ft_putstr("Ended successfully\n");
}
