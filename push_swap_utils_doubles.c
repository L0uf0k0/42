/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_doubles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:02:42 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/18 17:11:47 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_rr_r(t_l **l1, t_l **l2, t_l *cheap, int cond(t_l**, t_l**))
{
	while (cheap->sens == 22 && *l1 != cheap
		&& !cond(l2, &cheap))
		ft_rrr(l1, l2, 0);
	while (cheap->sens == 11 && *l1 != cheap
		&& !cond(l2, &cheap))
		ft_rr(l1, l2, 0);
}

void	ft_ss(t_l **lst1, t_l **lst2, int c)
{
	ft_swap(lst1, 'c');
	ft_swap(lst2, 'c');
	if (c != 'c')
		ft_putstr("ss\n");
}

void	ft_rr(t_l **lst1, t_l **lst2, int c)
{
	ft_rotate(lst1, 'c');
	ft_rotate(lst2, 'c');
	if (c != 'c')
		ft_putstr("rr\n");
}

void	ft_rrr(t_l **lst1, t_l **lst2, int c)
{
	ft_rev_rotate(lst1, 'c');
	ft_rev_rotate(lst2, 'c');
	if (c != 'c')
		ft_putstr("rrr\n");
}
