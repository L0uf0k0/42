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

char	***malloc_arr3(char ***arr, char *text);
{
	int	size3;

	size3 = count_w(text, '\n');
	arr = (char ***)malloc((size3 + 1) * sizeof(char **));
	if (!arr)
		return (NULL);
	return (arr);
}

char	**malloc_arr2(char **arr, char *text);
{
	int	size2;

	size2 = count_w(text, ' ');
	arr = (char **)malloc((size2 + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (arr);
}

int	***malloc_arr3_i(char ***arr, char **text);
{
	int	i;

	i = 0;
	while (text[i])
		i++;
	arr = (int ***)malloc((i + 1) * sizeof(int **));
	if (!arr)
		return (NULL);
	return (arr);
}

int	**malloc_arr2_i(char **arr, char *text);
{
	int	i;

	i = 0;
	while (text[i])
		i++;
	arr = (int **)malloc((i + 1) * sizeof(int *));
	if (!arr)
		return (NULL);
	return (arr);
}

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

void	ft_free_arr3(void ***arr, int i, int j)
{
	while (i > 0 && arr)
	{
		while (j > 0 && arr[i])
			free(arr[i][j--]);
		free(arr[i--]);
	}
	if (arr)
		free(arr);
}

int	***arr_atoi(int ***arr, char ***arr_txt)
{
	int	i;
	int	j;


	i = 0;
	if (!malloc_arr3_i(arr, arr_txt))
		return(ft_free_arr3(arr_txt));
	while (arr_txt[i++])
	{
		if (!malloc_arr2_i(arr[j], arr_txt[j]))
		{
			ft_free_arr3(arr)
			return(ft_free_arr3(arr_txt));
		}
		j = 0;
		while (arr_txt[i][j++])
		{
			arr[i][j] = ft_atoi(arr_txt[i][j]);
		}
	}
	ft_free_arr3(arr_txt3);
	return (arr);
}

int	***arr_construct(int ***arr, char *text)
{
	char	***arr_txt3;
	char	**arr_txt2;
	int	i;

	arr_txt2 = ft_split(text, '\n');
	while (arr_txt2[i])
	{
		arr_txt3[i] = ft_split(arr_txt2[i], ' ');
		if (!arr_txt3[i])
		{
			ft_free_arr3(arr_txt3);
			break ;
		}
		i++;
	}
	ft_free_arr(arr_txt2);
	if (!arr_txt3)
		return (NULL);
	return (arr_atoi(arr, arr_txt3));
}

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
	if (!arr_construct(arr, text))
		return (NULL);// faire fonction error pour close le fd aussi et tout free
	close (fd);
	return (arr);// verifier a la sortie si NULL
}
