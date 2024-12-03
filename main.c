/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:52:12 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/03 00:02:23 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_free_all(t_l **lst1, t_l **lst2, char *to_parse, char *str)
{
	t_l	*temp;

	while (*lst1)
	{
		temp = *lst1;
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
		free(to_parse);
		to_parse = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	return (to_parse);
}

int	main(int ac, char *av[])
{
	char	*to_parse;
	t_l		*lst1;
	t_l		*lst2;

	lst2 = NULL;
	lst1 = NULL;
	if (ac < 2)
		return (0);
	if (ac >= 2)
		to_parse = multiple_args(ac, av);
	else
		to_parse = av[1];
	if (!valid_num(to_parse))
		return (ft_free_all(&lst1, &lst2, to_parse, "Error"));
	lst1 = parser(to_parse);
	if (!lst1)
		return (ft_free_all(&lst1, &lst2, to_parse, "Error"));
	if (!check_dub(&lst1))
		return (ft_free_all(&lst1, &lst2, to_parse, "Error"));
	process(&lst1, &lst2);
	ft_free_all(&lst1, &lst2, to_parse, "");
}
