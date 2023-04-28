/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:03:27 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/16 13:35:14 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s)
	{
		if (*s != chr)
			s++;
		else
			return ((char *)s);
	}
	if (chr == '\0')
		return ((char *)s);
	return (NULL);
}
/*
int	main(void)
{
	char	str[];
	int		c;
    char *new_addres;

    str[] = "hola";
    c = '\0';
    new_addres = ft_strchr(str, c);
    if (!new_addres)
        printf("no encontre na");
    else
        printf("enconte %s", new_addres);
}
*/
