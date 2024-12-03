/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:23:18 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/03 09:33:50 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_choose(t_l **lst1, t_l **lst2, char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		ft_swap(lst1, 'a');
	if (str[0] == 's' && str[1] == 'b')
		ft_swap(lst2, 'b');
	if (str[0] == 's' && str[1] == 's')
		ft_ss(lst1, lst2);
	if (str[0] == 'p' && str[1] == 'a')
		ft_push(lst2, lst1, 'a');
	if (str[0] == 'p' && str[1] == 'b')
		ft_push(lst1, lst2, 'b');
	if (str[0] == 'r' && str[1] == 'a')
		ft_rotate(lst1, 'a');
	if (str[0] == 'r' && str[1] == 'b')
		ft_rotate(lst2, 'b');
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		ft_rr(lst1, lst2);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rev_rotate(lst1, 'a');
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rev_rotate(lst2, 'b');
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(lst1, lst2);
}
