
#include "fdf.h"

int	arr_size(char **arr)
{
	int	i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

int	arr_size_i(int **arr)
{
	int	i;

	i = 0;
	while(arr[i])
		i++;
	return (i);
}

void	ft_free_arr_i(int **arr, int i)
{
	while (i > 0 && arr)
		free(arr[i--]);
	if (arr)
		free(arr);
}


