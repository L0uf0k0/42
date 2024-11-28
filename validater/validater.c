/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:33:33 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/16 19:01:37 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"validater.h"
#include<stdio.h>

int	valid_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '-' && str[i] != '+' && str[i] != '\n')
		{
			ft_putstr("Only numbers and spaces please!\n");
			return (0);
		}
		else if (str[i] == '-' && str[i + 1] == '-')
		{
			ft_putstr("Valids numbers please!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_dub(t_list **list)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *list;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->data == temp2->data)
				return (0);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (1);
}
