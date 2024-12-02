/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:04:28 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 22:22:35 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_l	*ft_min_address(t_l *lst)
{
	t_l	*temp;
	t_l	*min;

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

int	ft_max(t_l *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	ft_min(t_l *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}
