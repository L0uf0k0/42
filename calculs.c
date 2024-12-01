/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/01 04:23:06 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

int	find_dist_b(t_list **lst2, t_list *node, int rot_a)
{
	t_list	*temp2;
	int	count;
	int	median;
	int	rot;

	temp2 = *lst2;
	count = 0;
	rot = (rot_a * 10) + 1;
	median = ft_lstsize(*lst2) / 2;
	while (temp2 && !push_back_cond(&temp2, &node))
	{
		count++;
		temp2 = temp2->next;
	}
	if (count > median)
		rot += 1;
	if (rot == 22)
		count = count - median;
	node->cost += count + 1;
	node->sens = rot;
	return (rot);
}

int	find_dist(t_list **lst1, t_list **lst2, t_list *node)
{
	t_list	*temp1;
	int	count;
	int	median;
	int	rot;

	rot = 1;
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
		rot = 2;
		count = count - median;
	}
	node->cost = count;
	return(find_dist_b(lst2, node, rot));
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

void	pass_with_rr_r(t_list **lst1, t_list **lst2, t_list *cheapest)
{
	while (cheapest->sens == 22 && *lst1 != cheapest
		&& !push_back_cond(lst2, &cheapest))
		ft_rrr(lst1, lst2);
	while (cheapest->sens == 11 && *lst1 != cheapest
		&& !push_back_cond(lst2, &cheapest))
		ft_rr(lst1, lst2);
}

void	pass_a_to_b(t_list **lst1, t_list **lst2, t_list *cheapest)
{
	pass_with_rr_r(lst1, lst2, cheapest);
	//show_list(lst1, lst2);
	while((*lst1)->data != cheapest->data)
	{
		if ((cheapest->sens) / 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
	while (*lst2 && !push_back_cond(lst2, &cheapest))
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
