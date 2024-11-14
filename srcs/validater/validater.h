/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:50:14 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/13 18:48:29 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATER_H
# define VALIDATER_H

# include<unistd.h>
//struct
typedef struct s_list
{
        struct s_list   *next;
	struct s_list	*prev;
        int            *data;
        int            needed;
}       t_list;

int	valid_num(char *str);
int	ft_isdigit(int c);
int	check_dub(t_list *list);
void	ft_putstr(char *s);

#endif
