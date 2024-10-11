/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:07:06 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/11 12:46:50 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_print_p(void *p);
void	ft_print_hex(unsigned int n, int type);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_printf(const char *str, ...);

#endif
