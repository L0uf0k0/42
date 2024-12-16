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

static int	*parse_line_to_ints(char *line)
{
	char	**split;
	int		word_count;
	int		*row;
	int		i;

	row = NULL;
	i = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	word_count = arr_size(split);
	row = malloc(sizeof(int) * word_count);
	if (!row)
		return (ft_free_arr(split, arr_size(split)), NULL);
	while (i < word_count && split[i])
	{
		row[i] = ft_atoi(split[i]);
		i++;
	}
	ft_free_arr(split, arr_size(split));
	return (row);
}

int	**parse_text_to_3d_array(char *text, int **arr)
{
	char	**lines;
	int	line_count;
	int	i;

	lines = ft_split(text, '\n');
	if (!lines)
		return (NULL);
	line_count = arr_size(lines);
	arr = malloc(sizeof(int *) * (line_count + 1));
	if (!arr)
		return (ft_free_arr(lines, arr_size(lines)), NULL);
	i = 0;
	while (i < line_count)
	{
		arr[i] = parse_line_to_ints(lines[i]);
		if (!arr[i])
		{
			ft_free_arr_i(arr, i);
			free(lines);
			return (NULL);
		}
		i++;
	}
	ft_free_arr(lines, arr_size(lines));
	arr[line_count] = NULL;
	return (arr);
}

char	*read_file(int fd)
{
	char	*buffer;
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	line = get_next_line(fd); // check
	while (line)
	{
		temp = ft_strjoin(buffer, line);
		free(buffer);
		free(line);
		if (!temp)
			return (NULL);
		buffer = temp;
		line = get_next_line(fd);
	}
	return (buffer);
}

int	**parser(const char *file)
{
	int	fd;
	char	*text;
	int	**arr;

	text = NULL;
	arr = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	text = read_file(fd);
	close(fd);
	if (!text)
		return (NULL);
	arr = parse_text_to_3d_array(text, arr);
	free(text);
	return (arr);
}

