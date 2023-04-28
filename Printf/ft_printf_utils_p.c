/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:47:25 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/24 18:15:28 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_pointer(unsigned long n)
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

int	ft_putpntr(unsigned long n)
{
	char	rst;
	int		len;

	len = ft_count_pointer(n);
	if (n > 15)
	{
		ft_putpntr(n / 16);
		ft_putpntr(n % 16);
	}
	else if (n > 9 && n < 16)
		ft_putchar((n - 10) + 'a');
	else if (n >= 0 && n <= 9)
	{
		rst = n + 48;
		ft_putchar(n + 48);
	}
	return (len);
}

int	ft_putpointer(unsigned long n)
{
	int	len;

	write(1, "0x", 2);
	len = ft_putpntr(n);
	return (len + 2);
}
