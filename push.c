/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:44:43 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 22:23:17 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_cond(t_l **lst, t_l **node)
{
	if (!*node)
		return (0);
	if ((*node)->data > (*lst)->data && (*node)->data < ft_lstlast(*lst)->data
		&& (*lst)->data < ft_lstlast(*lst)->data)
		return (1);
	if ((*node)->data > ft_max(*lst)
		&& (*lst)->data == ft_max(*lst))
		return (1);
	if ((*node)->data < ft_min(*lst)
		&& ft_lstlast(*lst)->data == ft_min(*lst))
		return (1);
	else
		return (0);
}

int	push_back_cond(t_l **lst, t_l **node)
{
	if (!*node)
		return (0);
	if ((*node)->data < (*lst)->data && (*node)->data > ft_lstlast(*lst)->data
		&& (*lst)->data > ft_lstlast(*lst)->data)
		return (1);
	if ((*node)->data > ft_max(*lst)
		&& ft_lstlast(*lst)->data == ft_max(*lst))
		return (1);
	if ((*node)->data < ft_min(*lst)
		&& (*lst)->data == ft_min(*lst))
		return (1);
	else
		return (0);
}

void	push_back(t_l **lst1, t_l **lst2, int size)
{
	while (!checker(lst1, lst2, size))
	{
		if (push_back_cond(lst1, lst2))
			ft_push(lst2, lst1, 'a');
		else
			ft_rotate(lst1, 'a');
	}
}
