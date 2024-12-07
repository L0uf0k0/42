/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:23:18 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/07 13:37:44 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error()
{
	ft_putstr("Error\n");
	return (-1);
}

int	ft_choose(t_l **lst1, t_l **lst2, char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		ft_swap(lst1, 'c');
	else if (str[0] == 's' && str[1] == 'b')
		ft_swap(lst2, 'c');
	else if (str[0] == 's' && str[1] == 's')
		ft_ss(lst1, lst2, 'c');
	else if (str[0] == 'p' && str[1] == 'a')
		ft_push(lst2, lst1, 'c');
	else if (str[0] == 'p' && str[1] == 'b')
		ft_push(lst1, lst2, 'c');
	else if (str[0] == 'r' && str[1] == 'a')
		ft_rotate(lst1, 'c');
	else if (str[0] == 'r' && str[1] == 'b')
		ft_rotate(lst2, 'c');
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		ft_rr(lst1, lst2, 'c');
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rev_rotate(lst1, 'c');
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rev_rotate(lst2, 'c');
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(lst1, lst2, 'c');
	else
		return (ft_error());
	return(0);
}

void	check_instructions(t_l *lst1, t_l *lst2, int size)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct)
	{
		if (ft_choose(&lst1, &lst2, instruct) == -1)
			break ;
		instruct = get_next_line(0);
	}
	free(instruct);
	if (!checker(&lst1, &lst2, size))
		return (ft_putstr("KO\n"));
	else
		return (ft_putstr("OK\n"));
}

int	 main(int ac, char *av[])
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
	check_instructions(lst1, lst2, ft_lstsize(lst1));
	ft_free_all(&lst1, &lst2, to_parse, "");
}
