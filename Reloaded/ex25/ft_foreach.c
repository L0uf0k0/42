/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:32:07 by malapoug          #+#    #+#             */
/*   Updated: 2024/09/12 00:27:53 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
void ft_putnbr (int n)
{
        char c;
        if ( n > 10)
                ft_putnbr(n / 10);
        c = (n % 10) + 48;
        write(1, &c, 1);
}

#include <unistd.h>
int main()
{
        int tab[] = {1, 2, 3, 4, 5};
        ft_foreach(tab, 5, &ft_putnbr);

}
*/
