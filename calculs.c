/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:11 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/30 16:03:03 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	instructions(t_list **lst1, t_list **lst2, int max_bits, int size)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			temp = *lst1;
			if (((temp->data >> i) & 1) == 0)
				ft_push(lst1, lst2, 'b');
			else
				ft_rotate(lst1, 'a');
			j++;
		}
		while (*lst2)
			ft_push(lst2, lst1, 'a');
		i++;
	}
}

void	rad_sort(t_list **lst1, t_list **lst2)
{
	t_list	*temp;
	int		max_bits;
	int		size;

	size = ft_lstsize(*lst1);
	max_bits = 0;
	temp = *lst1;
	while (temp)
	{
		if (temp->data > ((1 << max_bits) - 1))
			max_bits++;
		temp = temp->next;
	}
	instructions(lst1, lst2, max_bits, size);
}

/*
int ft_max(t_list *lst)
{
	int	 max;

	max = lst->data;
	while (lst)
	{
		if (lst->data < max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

void rad_sort(t_list **lst1, t_list **lst2)
{
	int	max;

	while (*lst1)
	{
		max = ft_max(*lst1);
		if ((*lst1)->data == max)
			ft_push(lst1, lst2, 'b');
		else
			ft_rotate(lst1, 'a');
	}
	while (*lst2)
		ft_push(lst2, lst1, 'a');
}
*/
