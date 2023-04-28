/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_cs_id.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:42:56 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/24 18:36:35 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_countdigits(int n)
{
	int	digs;

	digs = 0;
	if (n < 0)
	{
		n *= -1;
		digs += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		digs++;
	}
	if (n >= 0 && n <= 9)
		digs += 1;
	return (digs);
}

int	ft_putnbr(int n)
{
	int		len;

	len = ft_countdigits(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + 48);
	return (len);
}
