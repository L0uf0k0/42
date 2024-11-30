/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:22:28 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/30 16:23:04 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **lst1)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = (*lst1)->data;
	temp2 = (*lst1)->next->data;
	temp3 = (*lst1)->next->next->data;
	if (temp1 < temp2 && temp2 < temp3)
		return ;
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

void	sort5(t_list **lst1, t_list **lst2, int size)
{
	ft_push(lst1, lst2, 'b');
	ft_push(lst1, lst2, 'b');
	sort3(lst1);
	push_back(lst1, lst2, size);
}

void	sort4(t_list **lst1, t_list **lst2)
{
	ft_push(lst1, lst2, 'b');
	sort3(lst1);
	push_back(lst1, lst2, 4);
}

void	force_sort(t_list **lst1, t_list **lst2)
{
	int	size;

	size = ft_lstsize(*lst1);
	while (ft_lstsize(*lst1) > 5)
		ft_push(lst1, lst2, 'b');
	sort5(lst1, lst2, size);
}
