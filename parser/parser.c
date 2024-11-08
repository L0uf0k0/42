/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:03:46 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/08 15:43:06 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	list_constructor(t_list **base, t_list *new)
{
	if (!new)
		return (0);
	if (!(*base))
		*base = new;
	else
		ft_lstlast(*base)->next = new;
	return (1);
}

t_list	*parser(char *str)
{
	t_list	*list;
	char	**arr;
	int		temp;
	int		i;

	i = 0;
	list = NULL;
	arr = ft_split(str, ' ');
	while (arr[i])
	{
		temp = ft_atoi(arr[i]);
		if (!list_constructor(&list, ft_lstnew(temp)))
		{
			ft_lstclear(&list, free);
			break;
		}
		i++;
	}
	ft_free_arr(arr, i);
	return (list);
}

#include<stdio.h>

int main ()
{
	t_list *list = parser("0 1 2 3 4 5 6 7 8 9 10");
	while (list)
	{
		printf("%d\n", *(int *)(list->data));
		list = list->next;
	}
}
