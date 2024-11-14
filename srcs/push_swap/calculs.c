/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:29:21 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/14 02:30:29 by malapoug         ###   ########.fr       */
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


t_list	*find_cheapest(t_list **lst, t_list *node)
{
	t_list	*temp;
	t_list	*curr_cheap;
	int	size;
	int	count;

	size = ft_lstsize(lst1);
	temp = *lst;
	count = 0;
	curr_cheap = NULL;
	while (count < 5)
	{
		if
		count++;
	}
}


void	calcul(t_list **lst1, t_list **lst2)
{
	char	*str;

	str = find_cheapest;
	while

}
