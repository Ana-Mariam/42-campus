/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:33:36 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/27 15:07:45 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char	*num;
	int		digs;

	digs = ft_countdigits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		num = ft_calloc(digs + 1, (sizeof(char)));
		if (!num)
			return (NULL);
		if (n < 0)
		{
			num[0] = 45;
			n *= -1;
		}
		if (n == 0)
			num[0] = 48;
		while (n > 0)
		{
			num[--digs] = (n % 10) + 48;
			n = n / 10;
		}
	}
	return (num);
}

/*
int	main(void)
{
	printf("%s", ft_itoa(125));
	return (0);
}
*/
