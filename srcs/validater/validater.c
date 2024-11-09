/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:33:33 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/09 14:09:45 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"validater.h"

int	validater(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
		{
			ft_putstr("Only numbers and spaces please!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	checker(t_list *list)
{
	t_list	*lst;

	while (list)
	{
		lst = list->next;
		while (lst)
		{
			if (list->data == lst->data)
				return (0);
			lst = lst->next;
		}
		list = list->next;
	}
	return (1);
}
