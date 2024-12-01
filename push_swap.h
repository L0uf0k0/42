/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/01 19:54:31 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef PRINT
#  define PRINT 0
# endif

//struct
typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				cost;
	int				sens;
}	t_list;
//push_swap
void	ft_swap(t_list **list, int l);
void	ft_rotate(t_list **list, int l);
void	ft_rev_rotate(t_list **list, int l);
void	ft_push(t_list **lst1, t_list **lst2, int l);

//push_swap_utils
void	ft_swap(t_list **list, int l);
void	ft_rotate(t_list **list, int l);
void	ft_rev_rotate(t_list **list, int l);
void	ft_push(t_list **lst1, t_list **lst2, int l);

//push_swap_utils_doubles
void	ft_rr(t_list **lst1, t_list **lst2);
void	ft_rrr(t_list **lst1, t_list **lst2);

//process
void	process(t_list **lst1, t_list **lst2);
void	push_back(t_list **lst1, t_list **lst2, int size);
int		ft_max(t_list *lst);
int		ft_min(t_list *lst);

//force_sort
void	sort3(t_list **lst1);
void	sort4(t_list **lst1, t_list **lst2);
void	sort5(t_list **lst1, t_list **lst2, int size);
void	force_sort(t_list **lst1, t_list **lst2);

//calculs
void	calcul(t_list **lst1, t_list **lst2, int size);
//parser
t_list	*parser(char *str);
int		list_constructor(t_list **base, t_list *new);

//parser_utils
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int data);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
int		ft_isdigit(int c);

//validater
int	push_back_cond(t_list **lst1, t_list **lst2);
int	push_back_cond_inv(t_list **lst, t_list **node);
int		checker(t_list **lst1, t_list **lst2, int size);
int		valid_num(char *str);
int		check_dub(t_list **list);

//utils
void	ft_free_arr(char **arr, int i);
void	ft_putstr(char *s);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_free_all(t_list **lst1, t_list **lst2, char *to_parse, char *str);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);

//debug
void	show_list(t_list **lst1, t_list **lst2);
void	show_cost(t_list **lst);

#endif
