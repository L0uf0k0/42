/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:52:03 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/15 15:42:08 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	checker(t_list **lst1, t_list **lst2, int size)
{
	t_list	*lst;
	int	temp;

	if (ft_lstsize(*lst1) != size || ft_lstsize(*lst2) > 0)
		return (0);
	lst = *lst1;
	while (lst->next)
	{
		temp = *(lst->data);
		lst = lst->next;
		if (*(lst->data) < temp)
			return (0);
	}
	return (1);
}

void	sort3(t_list **lst1)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = *((*lst1)->data);
	temp2 = *((*lst1)->next->data);
	temp3 = *((*lst1)->next->next->data);
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
	else
		return;
}

void	process(t_list **lst1, t_list **lst2)
{
	int	size;

	size = ft_lstsize(*lst1);
	if (size == 3)
		sort3(lst1);
	show_list(lst1, lst2);
	while (!checker(lst1, lst2, size))
		calcul(lst1, lst2);
	ft_putstr("Ended successfully\n");
}
