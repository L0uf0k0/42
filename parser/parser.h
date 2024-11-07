/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:06:15 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/07 23:06:04 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include<stdlib.h>
//struct
typedef struct s_list
{
	int		*data;
	struct s_list	*prev;// a faire
	struct s_list	*next;
}	t_list;

//parser_utils.c
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_isdigit(int c);
t_list  *ft_lstnew(int *data);

//parser.c
int     list_constructor(t_list *base, t_list *new);
t_list  *parser(char *str);

#endif
