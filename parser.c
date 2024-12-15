/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:37:33 by malapoug          #+#    #+#             */
/*   Updated: 2024/12/14 17:37:38 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_arr_const(char *text, int*** arr)
{
	int	x;
	int	y;

	if (text == NULL)
	{
		arr = NULL;
		return ;
	}
	x = 0;
	y = 0;
	while (*text != '\0')
	{
		if (is_digit(*text))
			arr[y][x] *= 10 + (*text - '0')
		else if (*text == '\n')
			arr[y++][++x] = NULL; // y marche ??
		else
			x++;
		text++;
	}
	arr[++y] = NULL;
}

// faire un split de split...

char	*read_file( ***arr, int fd)
{
	char	*text;
	char	*temp;
	int	size;

	text = &"\0";
	size = -1
	while (size != ft_strlen(text) && text)
	{
		size = ft_strlen(text);
		temp =  get_next_line(fd);
		if (!temp)
		{
			if (text[0])
				free(text);
			arr = NULL;
			return ;
		}
		else
		{
			text = ft_strjoin(text, temp);
			if (!text)
				free(temp);
		}
	}
	return (text);
}

//                                                                       count_w(str, sep1, sep2) ??

int	***calloc_arr3(int ***arr, char *text);
{
	int	size3;

	size3 = count_w(text, '\n');
	arr = (int ***)malloc((size3 + 1) * sizeof(int **));
	if (!arr)
		return (NULL);
	return (arr);
}

int	**calloc_arr2(int **arr, char *text);
{
	int	size2;

	size2 = count_w(text, ' ');
	arr = (int **)malloc((size2 + 1) * sizeof(int *));
	if (!arr)
		return (NULL);
	return (arr);
}

int	*calloc_arr1(int *arr, char *text);
{
	arr = (int *)malloc(sizeof(int));
	if (!arr)
		return (NULL);
	return (arr);
}


int	***parser(char *file)
{
	char	*text;
	int	***arr;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);// faire fonction error pour close le fd aussi et tout free
	text = read_file(arr, fd);
	if (!text)
		return (NULL);
	if (!calloc_arr(arr, text))
		return (NULL);// faire fonction error pour close le fd aussi et tout free
	close (fd);
	return (arr);// verifier a la sortie si NULL
}
