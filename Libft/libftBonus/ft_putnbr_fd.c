/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:47:03 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/27 15:11:33 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	rst;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((-n), fd);
	}
	else if (n > 9)
	{
		rst = (n % 10) + 48;
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(rst, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		rst = n + 48;
		ft_putchar_fd(rst, fd);
	}
	return ;
}

/*
int	main(void)
{
    printf("%s",ft_putnbr_fd(int -5, int 1));
    return (0);
}
*/
