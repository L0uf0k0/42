/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 19:48:28 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include <stdio.h>

int	ft_calc_rr_r(int cost, int count)
{
	if (cost < count)
		return (count + 1);
	return (cost + 1);
}

int	find_dist_b(t_list **lst2, t_list *node, int rot_a, int cond(t_list**, t_list**))
{
	t_list	*temp2;
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
	if (rot == 22)
		node->cost = ft_calc_rr_r(node->cost, count);
	if (rot == 11)
		node->cost = ft_calc_rr_r(node->cost, count);
	else
		node->cost += count + 1;
	node->sens = rot;
	return (rot);
}

int	find_dist(t_list **lst1, t_list **lst2, t_list *node, int cond(t_list **, t_list**))
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
		count = ft_lstsize(*lst1) - count;
	}
	node->cost = count;
	node->sens = rot;
	return(find_dist_b(lst2, node, rot, cond));
}

/*
void	best_range(t_list **lst)
{
	t_list	*temp;

	if (!(*lst)->prev)
		return ;
	temp = (*lst)->next;
	while (temp && temp->next)
	{
		temp->cost += (temp->prev->cost) + (temp->next->cost);
		temp = temp->next;
	}
	ft_lstlast(*lst)->cost += (temp->prev->cost) + ((*lst)->cost);
}
*/

t_list	*find_cheapest(t_list **lst1, t_list **lst2, int cond(t_list**, t_list**))
{
	t_list	*temp1;
	t_list	*cheapest;

	temp1 = *lst1;
	while (temp1)
	{
		find_dist(lst1, lst2, temp1, cond);
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

void	pass_with_rr_r(t_list **lst1, t_list **lst2, t_list *cheapest, int cond(t_list**, t_list**))
{
	while (cheapest->sens == 22 && *lst1 != cheapest
		&& !cond(lst2, &cheapest))
		ft_rrr(lst1, lst2);
	while (cheapest->sens == 11 && *lst1 != cheapest
		&& !cond(lst2, &cheapest))
		ft_rr(lst1, lst2);
}

void	pass_a_to_b(t_list **lst1, t_list **lst2, t_list *cheapest)
{
	pass_with_rr_r(lst1, lst2, cheapest, push_back_cond_inv);
	while((*lst1) != cheapest && !push_back_cond_inv(lst2, lst1))
	{
		if ((cheapest->sens) / 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
	while (!push_back_cond_inv(lst2, lst1))
	{
		if ((cheapest->sens) % 10 == 1)
			ft_rotate(lst2, 'b');
		else
			ft_rev_rotate(lst2, 'b');
	}
	ft_push(lst1, lst2, 'b');
}

void	pass_b_to_a(t_list **lst1, t_list **lst2, t_list *cheapest)
{
	if (!(*lst2))
		return ;
	pass_with_rr_r(lst2, lst1, cheapest, push_back_cond);
	while((*lst2) != cheapest && !push_back_cond(lst1, lst2))
	{
		if ((cheapest->sens) / 10 == 1)
			ft_rotate(lst2, 'b');
		else
			ft_rev_rotate(lst2, 'b');
	}
	while (*lst1 && !push_back_cond(lst1, lst2))
	{
		if ((cheapest->sens) % 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
	ft_push(lst2, lst1, 'a');
}

void	last_rotate_a(t_list **lst1, t_list *cheapest)
{
	while((*lst1) != cheapest)
	{
		if ((cheapest->sens) / 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}

}

t_list	*ft_min_address(t_list *lst)
{
	t_list	*temp;
	t_list	 *min;

	temp = lst;
	min = temp;
	while (temp)
	{
		if (temp->data < min->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	push_back_algo(t_list **lst1, t_list **lst2, int size)
{
	t_list	*cheapest;

	while (!checker(lst1, lst2, size))
	{
		if (*lst2)
		{
			cheapest = find_cheapest(lst2, lst1, push_back_cond);
			//show_list(lst1, lst2);
			//show_cost(lst2);
			//printf("choisi:	%d\n\n\n", cheapest->data);
			pass_b_to_a(lst1, lst2, cheapest);
		}
		else
		{
			cheapest = ft_min_address(*lst1);
			cheapest->sens = find_dist(lst1, NULL, cheapest, push_back_cond);
			last_rotate_a(lst1, cheapest);
		}
	}
}

void	calcul(t_list **lst1, t_list **lst2, int size)
{
	t_list	*cheapest;

	if (*lst1 && ft_lstsize(*lst1) > 3)
	{
		cheapest = find_cheapest(lst1, lst2, push_back_cond_inv);
		//show_list(lst1, lst2);
		//show_cost(lst1);
		//printf("choisi:	%d\n\n\n", cheapest->data);
		pass_a_to_b(lst1, lst2, cheapest);
	}
	else
	{
		sort3(lst1);
		push_back_algo(lst1, lst2, size);
	}
}
