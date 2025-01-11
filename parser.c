/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:03:46 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/11 19:49:18 by malapoug         ###   ########.fr       */
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
	char		**arr;
	long int	temp;
	t_l			*list;
	int			i;

	i = 0;
	list = NULL;
	arr = ft_split(str, ' ');
	if (!arr)
		return (NULL);
	temp = 0;
	while (arr[i])
	{
		temp = ft_atoi(arr[i]);
		if (temp == 2147483649 || !list_constructor(&list, ft_lstnew(temp)))
		{
			ft_lstclear(&list, free);
			break ;
		}
		i++;
	}
	ft_free_arr(arr, arr_size(arr));
	return (list);
}
