/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/11 23:46:45 by malapoug         ###   ########.fr       */
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
int	checker(t_list **lst1, t_list **lst2, int size);
void	ft_choose(t_list **lst1, t_list **lst2, char *str);
void	ft_rotate(t_list **list, int l);
void	ft_rev_rotate(t_list **list, int l);
void	ft_push(t_list **lst1, t_list **lst2, int l);

void    ft_ss(t_list **lst1, t_list **lst2);
void    ft_rr(t_list **lst1, t_list **lst2);
void    ft_rrr(t_list **lst1, t_list **lst2);
//utils
int     valid_num(char *str);
void    ft_putstr(char *s);
int	check_dub(t_list *list);
t_list  *parser(char *str);
t_list	*ft_lstlast(t_list *list);
int	ft_lstsize(t_list *lst);

//debug
void	show_list(t_list **lst1, t_list **lst2);
#endif
