/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_uhex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:42:56 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/24 18:15:23 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countdigits_u(unsigned int n)
{
	int	digs;

	digs = 0;
	while (n > 9)
	{
		n = n / 10;
		digs++;
	}
	if (n >= 0 && n <= 9)
		digs += 1;
	return (digs);
}

int	ft_putnbr_u(unsigned int n)
{
	int	len;

	len = ft_countdigits_u(n);
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putchar(n % 10 + 48);
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	return (len);
}

int	ft_count_hex(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned int n, char const s)
{
	char	rst;
	int		len;

	len = ft_count_hex(n);
	if (n > 15)
	{
		ft_putnbr_hex(((n / 16)), s);
		ft_putnbr_hex((n % 16), s);
	}
	else if (n > 9 && n < 16)
	{
		if (s == 'X')
			ft_putchar((n - 10) + 'A');
		if (s == 'x')
			ft_putchar((n - 10) + 'a');
	}
	else if (n >= 0 && n <= 9)
	{
		rst = n + 48;
		ft_putchar(n + 48);
	}
	return (len);
}
