/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:41:52 by malapoug          #+#    #+#             */
/*   Updated: 2025/01/15 18:10:30 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_atoui(const char *hex_str)
{
	unsigned int	res;

	res = 0;
	if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X')) {
	hex_str += 2;
	}
	while (*hex_str)
	{
		res *= 16; // Décale à gauche en base 16
		if (*hex_str >= '0' && *hex_str <= '9')
			res += *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			res += *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			res += *hex_str - 'A' + 10;
		else
			return (0);
		hex_str++;
	}
	return (res);
}

unsigned int	get_color(t_vars *vars, t_br br)
{
	int	i;
	int	j;
	unsigned int	res;
	char	*temp;

	i = 0;
	j = 0;
	while (vars->char_lines[br.ty][i] && br.tx > 0)
	{
		if (vars->char_lines[br.ty][i] == ' ')
			br.tx--;
		i++;
	}
	if (!vars->char_lines[br.ty][i])
		return (0xFFFFFFF);
	while (vars->char_lines[br.ty][i + j] && vars->char_lines[br.ty][i + j] != ' ')
		j++;
	if (ft_strnstr(vars->char_lines[br.ty] + i, ",", j) == 0)
		return (0xFFFFFFFF);
	temp = ft_substr(ft_strnstr(vars->char_lines[br.ty] + i, ",", j), 1, 8);
	if (!temp)
		return (0xFFFFFF);
	res = ft_atoui(temp);
	return (free(temp), res);
}
