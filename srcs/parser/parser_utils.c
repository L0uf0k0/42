/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:16:31 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/25 16:57:17 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*arr;
	int		size;

	size = num_elements * element_size;
	arr = malloc(size);
	if (!arr)
		return (0);
	ft_memset(arr, 0, size);
	return (arr);
}

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = (t_list *)calloc(1, sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	new->cost = 0;
	new->sens = 11;
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
	del(&(*lst)->data);
	free(*lst);
	*lst = NULL;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next)
	{
		count += 1;
		lst = lst->next;
	}
	return (count);
}
