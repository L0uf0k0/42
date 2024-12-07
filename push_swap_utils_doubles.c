/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_doubles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:02:42 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/07 13:34:20 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
