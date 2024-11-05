/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malapoug <malapoug@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:07:06 by malapoug          #+#    #+#             */
/*   Updated: 2024/10/20 15:11:39 by malapoug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_print_p(void *p);
int	ft_print_hex(unsigned int n, int type, int cond);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_printf(const char *str, ...);

#endif
