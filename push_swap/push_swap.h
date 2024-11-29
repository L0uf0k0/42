/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/29 13:09:46 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
#include<unistd.h>
//struct
typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int	data;
	int	cost;
}	t_list;

void	ft_swap(t_list **list, int l);
void	process(t_list **lst1, t_list **lst2);
void	ft_choose(t_list **lst1, t_list **lst2, char *str);
void	ft_rotate(t_list **list, int l);
void	ft_rev_rotate(t_list **list, int l);
void	ft_push(t_list **lst1, t_list **lst2, int l);
void	calcul(t_list **lst1, t_list **lst2, int size);
int	checker(t_list **lst1, t_list **lst2, int size);
void	push_back(t_list **lst1, t_list **lst2, int size);
int ft_max(t_list *lst);

void	ft_ss(t_list **lst1, t_list **lst2);
void	ft_rr(t_list **lst1, t_list **lst2);
void	ft_rrr(t_list **lst1, t_list **lst2);
//utils
t_list	*parser(char *str);
t_list	*ft_lstlast(t_list *list);
void	ft_putstr(char *s);
int	 valid_num(char *str);
int	check_dub(t_list **list);
int	ft_lstsize(t_list *lst);
void	sort3(t_list **lst1);
int     find_dist(t_list **lst1, t_list **lst2, t_list *node);

void rad_sort(t_list **lst1, t_list **lst2, int size);
void index_list(t_list *lst);

//debug
void	show_list(t_list **lst1, t_list **lst2);
#endif
