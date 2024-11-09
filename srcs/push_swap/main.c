/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:52:12 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/09 01:40:22 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<stdio.h>

int main (int argc, char *argv[])
{
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("Only one argument please (\"1 2 3\")");
		return (-1);
	}
	if (!validater(argv[1]))
		return (-1);
        list = parser(argv[1]);
	if (!list)
		return (-1); //free
	if (!checker(list))
	{
		//free la liste
		ft_putstr("Only differents numbers please!");
		return (-1);
	}
        while (list)
        {
                printf("%d\n", *(int *)(list->data));
                list = list->next;
        }
}
