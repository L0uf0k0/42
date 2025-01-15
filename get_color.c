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

unsigned int hex_to_uint(const char *hex_str) {
    unsigned int result = 0;

    // Si la chaîne commence par "0x" ou "0X", on la saute
    if (hex_str[0] == '0' && (hex_str[1] == 'x' || hex_str[1] == 'X')) {
        hex_str += 2;
    }

    while (*hex_str) {
        result *= 16; // Décale à gauche en base 16
        if (*hex_str >= '0' && *hex_str <= '9') {
            result += *hex_str - '0';
        } else if (*hex_str >= 'a' && *hex_str <= 'f') {
            result += *hex_str - 'a' + 10;
        } else if (*hex_str >= 'A' && *hex_str <= 'F') {
            result += *hex_str - 'A' + 10;
        } else {
            // Caractère invalide dans la chaîne hexadécimale
            return 0;
        }
        hex_str++;
    }

    return result;
}

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
