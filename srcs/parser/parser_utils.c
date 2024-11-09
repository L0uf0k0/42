/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:16:31 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/08 15:32:34 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

t_list	*ft_lstnew(int data)
{
	t_list	*new;
	int		*temp;

	temp = malloc(sizeof(int) * 11);
	if (!temp)
		return (NULL);
	*temp = data;
	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(temp);
		return (NULL);
	}
	new->data = temp;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (last);
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, (*del));
	del((*lst)->data);
	free(*lst);
	*lst = NULL;
}
