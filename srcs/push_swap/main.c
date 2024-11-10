/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:52:12 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/10 19:46:02 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*lst1;
	t_list	*lst2;
	lst2 = NULL;
	if (argc != 2)
	{
		ft_putstr("Only one argument please (\"1 2 3\")\n");
		return (-1);
	}
	if (!valid_num(argv[1]))
		return (-1);
	lst1 = parser(argv[1]);
	if (!lst1)
		return (-1); //free
	if (!check_dub(lst1))
	{
		//free la liste
		ft_putstr("Only differents numbers please!\n");
		return (-1);
	}
	process(&lst1, &lst2);
}
