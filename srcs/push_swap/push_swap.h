/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/10 17:19:59 by malapoug         ###   ########.fr       */
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

void	ft_swap(t_list **list, int l);
void    process(t_list **lst1, t_list **lst2);
char    *calcul(t_list **lst1, t_list **lst2);
void	ft_choose(t_list **lst1, t_list **lst2, char *str);
void	ft_rotate(t_list **list, int l);
void	ft_rev_rotate(t_list **list, int l);
void	ft_push(t_list **lst1, t_list **lst2, int l);

void    ft_ss(t_list **lst1, t_list **lst2);
void    ft_rr(t_list **lst1, t_list **lst2);
void    ft_rrr(t_list **lst1, t_list **lst2);
//utils
int     validater(char *str);
void    ft_putstr(char *s);
t_list  *parser(char *str);
int	checker(t_list *list);
t_list	*ft_lstlast(t_list *list);
#endif
