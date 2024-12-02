/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 22:22:58 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process(t_l **lst1, t_l **lst2)
{
	int	size;

	size = ft_lstsize(*lst1);
	if (size == 2 && !checker(lst1, lst2, size))
		ft_swap(lst1, 'a');
	else if (size == 3)
		sort3(lst1);
	else if (size == 4)
		sort4(lst1, lst2);
	else if (size == 5)
		sort5(lst1, lst2, size);
	else if (size > 5 && !checker(lst1, lst2, size))
	{
		ft_push(lst1, lst2, 'b');
		ft_push(lst1, lst2, 'b');
		while (!checker(lst1, lst2, size))
			calcul(lst1, lst2, size);
	}
}
