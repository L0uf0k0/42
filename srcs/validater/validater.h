/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validater.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:50:14 by malapoug          #+#    #+#             */
/*   Updated: 2024/11/09 14:40:08 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATER_H
# define VALIDATER_H

# include<unistd.h>
//struct
typedef struct s_list
{
        int            *data;
        struct s_list   *next;
	struct s_list	*prev;
}       t_list;

int	validater(char *str);
int	ft_isdigit(int c);
int	checker(t_list *list);
void	ft_putstr(char *s);

#endif
