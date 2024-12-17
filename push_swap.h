/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/07 18:20:41 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//struct
typedef struct s_l
{
	struct s_l	*next;
	struct s_l	*prev;
	int			data;
	int			cost;
	int			sens;
}		t_l;

//main
char	*multiple_args(int ac, char **av);

//push_swap
void	ft_swap(t_l **list, int l);
void	ft_rotate(t_l **list, int l);
void	ft_rev_rotate(t_l **list, int l);
void	ft_push(t_l **lst1, t_l **lst2, int l);

//push_swap_utils
void	ft_swap(t_l **list, int l);
void	ft_rotate(t_l **list, int l);
void	ft_rev_rotate(t_l **list, int l);
void	ft_push(t_l **lst1, t_l **lst2, int l);

//push_swap_utils_doubles
void	ft_ss(t_l **list1, t_l **lst2, int c);
void	ft_rr(t_l **lst1, t_l **lst2, int c);
void	ft_rrr(t_l **lst1, t_l **lst2, int c);

//process
void	process(t_l **lst1, t_l **lst2);

//min_max
t_l		*ft_max_address(t_l *lst);
t_l		*ft_min_address(t_l *lst);
int		ft_max(t_l *lst);
int		ft_min(t_l *lst);

//process2
void	pass_rr_r(t_l **l1, t_l **l2, t_l *cheap, int cond(t_l**, t_l**));
void	push_back_algo(t_l **lst1, t_l **lst2, int size);
void	pass_rr_r(t_l **l1, t_l **l2, t_l *cheap, int cond(t_l**, t_l**));
void	pass_a_to_b(t_l **lst1, t_l **lst2, t_l *cheapest);
void	pass_b_to_a(t_l **lst1, t_l **lst2, t_l *cheapest);

//push
void	push_back(t_l **lst1, t_l **lst2, int size);
int		push_back_cond(t_l **lst1, t_l **lst2);
int		push_cond(t_l **lst, t_l **node);

//force_sort
void	sort3(t_l **lst1);
void	sort4(t_l **lst1, t_l **lst2);
void	sort5(t_l **lst1, t_l **lst2);

//calculs
void	calcul(t_l **lst1, t_l **lst2, int size);
int		ft_calc_rr_r(int cost, int count);
int		find_dist(t_l **lst1, t_l **lst2, t_l *node, int cond(t_l **, t_l**));
int		find_dist_b(t_l **lst2, t_l *node, int rot_a, int cond(t_l**, t_l**));
t_l		*find_cheap(t_l **lst1, t_l **lst2, int cond(t_l**, t_l**));

//parser
t_l		*parser(char *str);
int		list_constructor(t_l **base, t_l *new);

//parser_utils
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
void	ft_lstclear(t_l **lst, void (*del)(void *));
t_l		*ft_lstlast(t_l *lst);
t_l		*ft_lstnew(int data);
int		ft_lstsize(t_l *lst);
int		ft_isdigit(int c);

//validater
void	check_rot(t_l *node, int rot, int count);
int		checker(t_l **lst1, t_l **lst2, int size);
int		valid_num(char *str);
int		check_dub(t_l **list);

//utils
void	ft_free_arr(char **arr, int i);
void	ft_putstr(char *s);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_free_all(t_l **lst1, t_l **lst2, char *to_parse, char *str);
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);

//get_next_line
char	*get_next_line(int fd);

//debug
void	show_list(t_l **lst1, t_l **lst2);
void	show_cost(t_l **lst);

#endif
