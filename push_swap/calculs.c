/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/25 17:45:00 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
//#include<stdio.h>

int	find_dist_b(t_list **lst2, t_list *node, int ret_a)
{
	t_list	*temp2;
	int	count;
	int	median;
	int	ret;

	temp2 = *lst2;
	count = 0;
	ret = (ret_a * 10) + 1;
	median = ft_lstsize(*lst2) / 2;
	while (temp2 && (((node)->data < (temp2)->data && (((temp2)->data < ft_lstlast(temp2)->data && (node)->data < ft_lstlast(temp2)->data) || (node)->data > ft_lstlast(temp2)->data)) || ((node)->data > ft_max(temp2) && ft_lstlast(temp2)->data == ft_max(temp2))))
	{
		count++;
		temp2 = temp2->next;
	}
	if (count > median && ret / 10 == 2)
	{
		ret += 1;
		count = count - median;
	}
	node->cost += count + 1;
	node->sens = ret;
	return (ret);
}

int	find_dist(t_list **lst1, t_list **lst2, t_list *node)
{
	t_list	*temp1;
	int	count;
	int	median;
	int	ret;

	ret = 1;
	temp1 = *lst1;
	count = 0;
	median = ft_lstsize(*lst1) / 2;
	while (temp1 && temp1 != node)
	{
		count ++;
		temp1 = temp1->next;
	}
	if (count > median)
	{
		ret = 2;
		count = count - median;
	}
	node->cost = count;
	return(find_dist_b(lst2, node, ret));
}

t_list	*find_cheapest(t_list **lst1, t_list **lst2)
{
	t_list	*temp1;
	t_list	*cheapest;

	temp1 = *lst1;
	while (temp1)
	{
		find_dist(lst1, lst2, temp1);
		temp1 = temp1->next;
	}
	temp1 = *lst1;
	cheapest = temp1;
	while(temp1)
	{
		if (temp1->cost < cheapest->cost)
			cheapest = temp1;
		temp1 = temp1->next;
	}

	return (cheapest);
}

void	pass_a_to_b(t_list **lst1, t_list **lst2, t_list *cheapest)
{
	while(!cheapest && *lst1 != cheapest)
	{
		if ((cheapest->sens) / 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
	while (*lst2 && (((cheapest)->data < (*lst2)->data && (((*lst2)->data < ft_lstlast(*lst2)->data && (cheapest)->data < ft_lstlast(*lst2)->data) || (cheapest)->data > ft_lstlast(*lst2)->data)) || ((cheapest)->data > ft_max(*lst2) && ft_lstlast(*lst2)->data == ft_max(*lst2))))
	{
		if ((cheapest->sens) % 10 == 1)
			ft_rotate(lst2, 'b');
		else
			ft_rev_rotate(lst2, 'b');
	}
	ft_push(lst1, lst2, 'b');
}

void	calcul(t_list **lst1, t_list **lst2, int size)
{
	t_list	*cheapest;

	ft_push(lst1, lst2, 'b');
	ft_push(lst1, lst2, 'b');
	if (*lst1 && ft_lstsize(*lst1) > 3)
	{
		cheapest = find_cheapest(lst1, lst2);
		pass_a_to_b(lst1, lst2, cheapest);
	}
	else
	{
		sort3(lst1);
		push_back(lst1, lst2, size);
	}
}
