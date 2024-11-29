/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:11 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/29 13:16:34 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *stack, int data)
{
	int index = 0;
	t_list *current = stack;

	while (current)
	{
		if (current->data < data)
			index++;
		current = current->next;
	}
	return (index);
}

void index_list(t_list *lst)
{
	t_list *current = lst;

	while (current)
	{
		current->cost = get_index(lst, current->data);
		current = current->next;
	}
}

void radix_pass(t_list **lst1, t_list **lst2, int bit_pos, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (((*lst1)->cost >> bit_pos) & 1)
			ft_rotate(lst1, 'a');
		else
			ft_push(lst1, lst2, 'b');
		i++;
	}
	while (*lst1)
		ft_push(lst2, lst1, 'a');
}


void rad_sort(t_list **lst1, t_list **lst2, int size)
{
	int max_bits;
	t_list *current;
	int	i;

	i = 0;
	max_bits = 0;
	current = *lst1;
	while (current)
	{
		if (current->cost > max_bits)
			max_bits = current->cost;
		current = current->next;
	}
	max_bits = 0;
	while ((1 << max_bits) < size)
		max_bits++;

	while (i < max_bits)
	{
		radix_pass(lst1, lst2, i, size);
		i++;
	}
}

