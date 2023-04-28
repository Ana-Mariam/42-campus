/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:21:46 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/24 18:31:06 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_countdigits(int n);
int	ft_putnbr(int n);
int	ft_putnbr_hex(unsigned int n, char const s);
int	ft_count_hex(unsigned int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putpointer(unsigned long n);
int	ft_putpntr(unsigned long n);
int	ft_printf(char const *str, ...);

#endif
