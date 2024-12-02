/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_doubles.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:02:42 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 22:23:30 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_l **lst1, t_l **lst2)
{
	ft_swap(lst1, 'c');
	ft_swap(lst2, 'c');
	ft_putstr("ss\n");
}

void	ft_rr(t_l **lst1, t_l **lst2)
{
	ft_rotate(lst1, 'c');
	ft_rotate(lst2, 'c');
	ft_putstr("rr\n");
}

void	ft_rrr(t_l **lst1, t_l **lst2)
{
	ft_rev_rotate(lst1, 'c');
	ft_rev_rotate(lst2, 'c');
	ft_putstr("rrr\n");
}
