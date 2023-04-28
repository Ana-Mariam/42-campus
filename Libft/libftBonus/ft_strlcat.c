/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:28:10 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/21 17:41:17 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	total;
	size_t	i;
	size_t	j;

	if (dstsize == 0 && (!dst || !src))
		return (0);
	i = 0;
	total = ft_strlen(src);
	j = ft_strlen(dst);
	if (dstsize == 0)
		return (total);
	if (dstsize <= j)
		total += dstsize;
	else
		total += j;
	i = 0;
	while ((src[i] != '\0') && (j < (dstsize - 1)))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (total);
}
