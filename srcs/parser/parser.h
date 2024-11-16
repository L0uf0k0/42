/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/16 19:03:23 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include<stdlib.h>
# include<unistd.h>
//struct
typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int	data;
	int	cost;
	int	sens;
}	t_list;

//ft_split.c
char    **ft_split(const char *s, char c);
void     ft_free_arr(char **arr, int i);

//ft_atoi.c
int     ft_atoi(const char *str);

//ft_substr.c
char     *ret_null_p(int i);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(const char *str);

//parser_utils.h
t_list  *ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int	ft_lstsize(t_list *lst);

//parser.c
int     list_constructor(t_list **base, t_list *new);
t_list  *parser(char *str);

#endif
