/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:09:52 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/24 18:31:56 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_t_var(va_list args, char const s)
{
	int		len;

	len = 0;
	if (s == 'c')
		len = ft_putchar(va_arg(args, int));
	if (s == 's')
		len = ft_putstr(va_arg(args, char *));
	if (s == 'p')
		len += ft_putpointer(va_arg(args, unsigned long));
	if (s == 'i' || s == 'd')
		len += ft_putnbr(va_arg(args, int));
	if (s == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	if (s == 'x' || s == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), s);
	if (s == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = -1;
	len = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_t_var(args, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
	}
	va_end(args);
	return (len);
}

/* int main ()
{
    int x;
    int y;
	char *a;
	
	a = "Probando";
    
    x = ft_printf("Hoola %c %s %%   %i   %x %u %p ", 'D', "ABCDE", 7, -489225,
		-19, a);
    printf("\n");
    y = printf("Hoola %c %s %%   %i   %x %u %p ", 'D', "ABCDE", 7, -489225, -19,
		a);
    printf("\n");
    printf("%d\t", x);
    printf("%d", y);
    return (0);
}  */
