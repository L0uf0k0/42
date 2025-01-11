/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:23:18 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/11 19:43:07 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_error(void)
{
	ft_putstr("Error\n");
	return (-1);
}

int	ft_choose2(t_l **lst1, t_l **lst2, char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == '\0')
		ft_rr(lst1, lst2, 'c');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a'
		&& (s[3] == '\n' || s[3] == '\0'))
		ft_rev_rotate(lst1, 'c');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b'
		&& (s[3] == '\n' || s[3] == '\0'))
		ft_rev_rotate(lst2, 'c');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r'
		&& (s[3] == '\n' || s[3] == '\0'))
		ft_rrr(lst1, lst2, 'c');
	else
		return (ft_error(), -1);
	return (0);
}

int	ft_choose(t_l **lst1, t_l **lst2, char *s)
{
	if (s[0] == 's' && s[1] == 'a' && (s[2] == '\n' || s[2] == '\0'))
		ft_swap(lst1, 'c');
	else if (s[0] == 's' && s[1] == 'b' && (s[2] == '\n' || s[2] == '\0'))
		ft_swap(lst2, 'c');
	else if (s[0] == 's' && s[1] == 's' && (s[2] == '\n' || s[2] == '\0'))
		ft_ss(lst1, lst2, 'c');
	else if (s[0] == 'p' && s[1] == 'a' && (s[2] == '\n' || s[2] == '\0'))
		ft_push(lst2, lst1, 'c');
	else if (s[0] == 'p' && s[1] == 'b' && (s[2] == '\n' || s[2] == '\0'))
		ft_push(lst1, lst2, 'c');
	else if (s[0] == 'r' && s[1] == 'a' && (s[2] == '\n' || s[2] == '\0'))
		ft_rotate(lst1, 'c');
	else if (s[0] == 'r' && s[1] == 'b' && (s[2] == '\n' || s[2] == '\0'))
		ft_rotate(lst2, 'c');
	else
		return (ft_choose2(lst1, lst2, s));
	return (0);
}

void	check_instructions(t_l *lst1, t_l *lst2, int size)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct)
	{
		if (ft_choose(&lst1, &lst2, instruct) == -1)
			return (free(instruct));
		free(instruct);
		instruct = get_next_line(0);
	}
	free(instruct);
	if (!checker(&lst1, &lst2, size))
		return (ft_putstr("KO\n"));
	else
		return (ft_putstr("OK\n"));
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
		return (ft_free_all(&lst1, &lst2, to_parse, "Error\n"));
	lst1 = parser(to_parse);
	if (!lst1)
		return (ft_free_all(&lst1, &lst2, to_parse, "Error\n"));
	if (!check_dub(&lst1))
		return (ft_free_all(&lst1, &lst2, to_parse, "Error\n"));
	check_instructions(lst1, lst2, ft_lstsize(lst1));
	ft_free_all(&lst1, &lst2, to_parse, "");
}
