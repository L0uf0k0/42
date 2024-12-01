/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:00:56 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/01 19:55:09 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	show_cost(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	printf("Costs:\n");
	while (temp)
	{
		printf("%d :	", temp->data);
		printf("cost %d\n", temp->cost);
		temp = temp->next;
	}

}

void	show_list(t_list **lst1, t_list **lst2)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *lst1;
	temp2 = *lst2;
	printf("Liste 1:\n");
	while (temp1)
	{
		printf("%d\n", temp1->data);
		temp1 = temp1->next;
	}
	printf("\n\nListe 2:\n");
	while (temp2)
	{
		printf("%d\n", temp2->data);
		temp2 = temp2->next;
	}
	printf("\n\n\n");
}
