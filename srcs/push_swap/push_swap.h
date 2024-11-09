/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/09 15:27:16 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
//struct
typedef struct s_list
{
	int	*data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	ft_swap(t_list **list);
void	ft_rotate(t_list **list);
void	ft_rev_rotate(t_list **list);

//utils
int     validater(char *str);
void    ft_putstr(char *s);
t_list  *parser(char *str);
int	checker(t_list *list);
t_list	*ft_lstlast(t_list *list);
#endif
