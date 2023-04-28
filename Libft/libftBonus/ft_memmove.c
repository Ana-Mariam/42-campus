/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:09:15 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/15 16:38:51 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	while (dst < src)
		return (ft_memcpy(dst, src, len));
	if (src < dst)
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}

/*
#include <stdio.h>
int main()
{
	printf("%s", ft_memmove("HelloWorld", "ABCDEFG", 5));
	return (0);
}
*/

/*Overlap es cuando dos cadenas comparten posiciones de memorias pero en i 
diferentes, el problema en esta función es cuando dest, está posicionada 
más hacia la drcha que src.*/
