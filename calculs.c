/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/18 17:14:10 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calc_rr_r(int cost, int count)
{
	if (cost < count)
		return (count + 1);
	return (cost + 1);
}

int	find_dist_b(t_l **lst2, t_l *node, int rot_a, int cond(t_l**, t_l**))
{
	t_l	*temp2;
	int	count;
	int	median;
	int	rot;

	if (!(lst2))
		return (rot_a * 10);
	temp2 = *lst2;
	count = 0;
	rot = (rot_a * 10) + 1;
	median = ft_lstsize(*lst2) / 2;
	while (temp2 && !cond(&temp2, &node))
	{
		count++;
		temp2 = temp2->next;
	}
	if (count > median)
	{
		rot += 1;
		count = ft_lstsize(*lst2) - count;
	}
	check_rot(node, rot, count);
	node->sens = rot;
	return (rot);
}

int	find_dist(t_l **lst1, t_l **lst2, t_l *node, int cond(t_l **, t_l**))
{
	t_l	*temp1;
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
		count = ft_lstsize(*lst1) - count;
	}
	node->cost = count;
	node->sens = rot;
	return (find_dist_b(lst2, node, rot, cond));
}

t_l	*find_cheap(t_l **lst1, t_l **lst2, int cond(t_l**, t_l**))
{
	t_l	*temp1;
	t_l	*cheap;

	temp1 = *lst1;
	while (temp1)
	{
		find_dist(lst1, lst2, temp1, cond);
		temp1 = temp1->next;
	}
	temp1 = *lst1;
	cheap = temp1;
	while (temp1)
	{
		if (temp1->cost < cheap->cost)
			cheap = temp1;
		temp1 = temp1->next;
	}
	return (cheap);
}

void	calcul(t_l **lst1, t_l **lst2, int size)
{
	t_l	*cheap;

	if (*lst1 && ft_lstsize(*lst1) > 3)
	{
		cheap = find_cheap(lst1, lst2, push_cond);
		pass_a_to_b(lst1, lst2, cheap);
	}
	else
	{
		sort3(lst1);
		push_back_algo(lst1, lst2, size);
	}
}
