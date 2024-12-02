/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 22:29:30 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_rr_r(t_l **l1, t_l **l2, t_l *cheap, int cond(t_l**, t_l**))
{
	while (cheap->sens == 22 && *l1 != cheap
		&& !cond(l2, &cheap))
		ft_rrr(l1, l2);
	while (cheap->sens == 11 && *l1 != cheap
		&& !cond(l2, &cheap))
		ft_rr(l1, l2);
}

void	pass_a_to_b(t_l **lst1, t_l **lst2, t_l *cheap)
{
	pass_rr_r(lst1, lst2, cheap, push_cond);
	while ((*lst1) != cheap && !push_cond(lst2, lst1))
	{
		if ((cheap->sens) / 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
	while (!push_cond(lst2, lst1))
	{
		if ((cheap->sens) % 10 == 1)
			ft_rotate(lst2, 'b');
		else
			ft_rev_rotate(lst2, 'b');
	}
	ft_push(lst1, lst2, 'b');
}

void	pass_b_to_a(t_l **lst1, t_l **lst2, t_l *cheap)
{
	if (!(*lst2))
		return ;
	pass_rr_r(lst2, lst1, cheap, push_back_cond);
	while ((*lst2) != cheap && !push_back_cond(lst1, lst2))
	{
		if ((cheap->sens) / 10 == 1)
			ft_rotate(lst2, 'b');
		else
			ft_rev_rotate(lst2, 'b');
	}
	while (*lst1 && !push_back_cond(lst1, lst2))
	{
		if ((cheap->sens) % 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
	ft_push(lst2, lst1, 'a');
}

void	last_rotate_a(t_l **lst1, t_l *cheap)
{
	while ((*lst1) != cheap)
	{
		if ((cheap->sens) / 10 == 1)
			ft_rotate(lst1, 'a');
		else
			ft_rev_rotate(lst1, 'a');
	}
}

void	push_back_algo(t_l **lst1, t_l **lst2, int size)
{
	t_l	*cheap;

	while (!checker(lst1, lst2, size))
	{
		if (*lst2)
		{
			cheap = find_cheap(lst2, lst1, push_back_cond);
			pass_b_to_a(lst1, lst2, cheap);
		}
		else
		{
			cheap = ft_min_address(*lst1);
			cheap->sens = find_dist(lst1, NULL, cheap, push_back_cond);
			last_rotate_a(lst1, cheap);
		}
	}
}
