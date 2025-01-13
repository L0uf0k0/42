/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:52:12 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/13 15:27:57 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_free_all(t_l **lst1, t_l **lst2, char *to_parse, char *str)
{
	t_l	*temp;

	while (*lst1)
	{
		temp = (*lst1);
		(*lst1) = (*lst1)->next;
		free(temp);
	}
	while (*lst2)
	{
		temp = *lst2;
		(*lst2) = (*lst2)->next;
		free(temp);
	}
	if (to_parse)
		free(to_parse);
	ft_putstr(str);
	return (1);
}

char	*multiple_args(int ac, char **av)
{
	char	*to_parse;
	char	*tmp;
	int		i;

	i = 1;
	to_parse = NULL;
	while (i < ac)
	{
		tmp = ft_strjoin(to_parse, av[i]);
		if (!tmp)
			return (NULL);
		free(to_parse);
		to_parse = ft_strjoin(tmp, " ");
		free(tmp);
		if (!to_parse)
			return (NULL);
		i++;
	}
	return (to_parse);
}
