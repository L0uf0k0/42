/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:52:03 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/12 00:54:31 by malapoug         ###   ########.fr       */
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
}//supprimer ?

int	checker(t_list **lst1, t_list **lst2, int size)
{
	t_list	*lst;
	int	temp;

	if (ft_lstsize(*lst1) != size || ft_lstsize(*lst2) > 0)
		return (0);
	lst = *lst1;
	while (lst->next)
	{
		temp = *(lst->data);
		lst = lst->next;
		if (*(lst->data) < temp)
			return (0);
	}
	return (1);
}

void	sort3(t_list **lst1)
{
	int	temp1;
	int	temp2;
	int	temp3;

	temp1 = *((*lst1)->data);
	temp2 = *((*lst1)->next->data);
	temp3 = *((*lst1)->next->next->data);
	if (temp1 < temp2 && temp1 < temp3)
	{
		ft_swap(lst1, 'a');
		ft_rotate(lst1, 'a');
	}
	else if (temp1 > temp2 && temp1 < temp3)
		ft_swap(lst1, 'a');
	else if (temp1 < temp2 && temp1 > temp3)
		ft_rev_rotate(lst1, 'a');
	else if (temp1 > temp2 && temp2 < temp3)
		ft_rotate(lst1, 'a');
	else if (temp1 > temp2 && temp2 > temp3)
	{
		ft_swap(lst1, 'a');
		ft_rev_rotate(lst1, 'a');
	}
	else
		return;
}

void	process(t_list **lst1, t_list **lst2)
{
	int	size;

	size = ft_lstsize(*lst1);
	if (ft_lstsize(*lst1) < 4)
		sort3(lst1);
	show_list(lst1, lst2);
	(void)size;
	while (!checker(lst1, lst2, size))
		//calcul(lst1, lst2);
	ft_putstr("Ended successfully\n");
}
