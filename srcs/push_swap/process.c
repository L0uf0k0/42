/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:52:03 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/10 23:19:48 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void ft_choose(t_list **lst1, t_list **lst2, char *str)
{
	if (str[0] == 's' && str[1] == 'a')
		ft_swap(lst1, 'a');
	if (str[0] == 's' && str[1] == 'b')
		ft_swap(lst2, 'b');
	if (str[0] == 's' && str[1] == 's')
		ft_ss(lst1, lst2);
	if (str[0] == 'p' && str[1] == 'a')
		ft_push(lst2, lst1, 'a');
	if (str[0] == 'p' && str[1] == 'b')
		ft_push(lst1, lst2, 'b');
	if (str[0] == 'r' && str[1] == 'a')
		ft_rotate(lst1, 'a');
	if (str[0] == 'r' && str[1] == 'b')
		ft_rotate(lst2, 'b');
	if (str[0] == 'r' && str[1] == 'r' && str[2] == '\0')
		ft_rr(lst1, lst2);
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		ft_rev_rotate(lst1, 'a');
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		ft_rev_rotate(lst2, 'b');
	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		ft_rrr(lst1, lst2);
}

int	checker(t_list **lst1, t_list **lst2)
{
	t_list	*lst;
	int	temp;

	if (!*lst1)
		return (1);
	temp = *((*lst1)->data);
	lst = *lst1;
	while (lst)
	{
		if (*lst2 || (*(lst->data) < temp))
			return (0);
		temp = *(lst->data);
		lst = lst->next;

	}
	return (1);
}

int	 avarage(t_list **lst)
{
	t_list  *temp;
	int	 res;
	int	 count;

	temp = *lst;
	res = 0;
	count = 0;
	while (temp)
	{
		res += *(temp->data);
		temp = temp->next;
		count++;
	}
	return (res / count);
}

void	first_sort(t_list **lst1, t_list **lst2, int avarage)
{
	int	 size;

	size = ft_lstsize(*lst1);
	while (*lst1 && size > 0)
	{
		if (*((*lst1)->data) > avarage)
			ft_push(lst1, lst2, 'b');
		else
			ft_rotate(lst1, 'a');
		size--;
	}
}

void	process(t_list **lst1, t_list **lst2)
{
	char	*str;

	first_sort(lst1, lst2, avarage(lst1));
	while (!checker(lst1, lst2))
	{
		str = calcul(lst1, lst2);
		ft_choose(lst1, lst2, str);
	}
	ft_putstr("Ended successfully\n");
}
