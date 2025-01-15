/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:52 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/15 17:21:35 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	get_color(t_vars *vars, t_br br)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->char_lines[br.ty][i] && br.tx > 0)
	{
		if (vars->char_lines[br.ty][i] == ' ')
			br.tx--;
		i++;
	}
	if (!vars->char_lines[br.ty][i])
		return (0xFFFFFFFF);
	while (vars->char_lines[br.ty][i + j] && vars->char_lines[br.ty][i + j] != ' ')
		j++;
	return (0xFFFFFF);//(unsigned int)ft_substr(ft_strnstr(vars->char_lines[br.ty] + i, ",", j), 1, 8));
}
