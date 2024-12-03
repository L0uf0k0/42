/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:03:46 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/02 23:51:52 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_constructor(t_l **base, t_l *new)
{
	if (!new)
		return (0);
	if (!base || !(*base))
		*base = new;
	else
	{
		new->prev = ft_lstlast(*base);
		ft_lstlast(*base)->next = new;
	}
	(*base)->prev = ft_lstlast(*base);
	return (1);
}

t_l	*parser(char *str)
{
	char	**arr;
	t_l		*list;
	int		temp;
	int		i;

	i = 0;
	list = NULL;
	arr = ft_split(str, ' ');
	if (!arr)
		return (NULL);
	temp = 0;
	while (arr[i])
	{
		temp = ft_atoi(arr[i]);
		if (!list_constructor(&list, ft_lstnew(temp)))
		{
			ft_lstclear(&list, free);
			break ;
		}
		i++;
	}
	ft_free_arr(arr, i);
	return (list);
}