/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:03:46 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/07 23:23:16 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	list_constructor(t_list *base, t_list *new)
{
	if (!new)
		return (0);
	if (!base)
		base = new;
	else
		base->next = new;
	return (1);
}

t_list	*parser(char *str)
{
	t_list	*list;
	int	*temp;
	int	signe;

	list = NULL;
	while (*str)
	{
		signe = 1;
		temp = 0;
		while (ft_isdigit(*str) || *str == '-')// checker ?
		{
			if (*str == '-')
			{
				signe = -1;
				str++;
			}
			*temp = ((*temp) * 10) + (*str - '0');// error right here
			if (!ft_isdigit(*str + 1))
			{
				*temp *= signe;
				//if (!
				list_constructor(list, ft_lstnew(temp));//)
				//	free_list(list); // a faire
				str++;
			}
			//if *str == \0 ?
		}
		str++;
	}
	return (list);
}

#include<stdio.h>

int main ()
{
	t_list *list = parser("12");
	while (list)
	{
		printf("%d", *(list->data));
		//list = list->next;
	}
}
