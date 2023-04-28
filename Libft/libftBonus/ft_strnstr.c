/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:43:54 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/21 17:44:38 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0 && (!str || !to_find))
		return (0);
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && (i < len))
	{
		if (str[i] == *to_find)
		{
			j = 0;
			while (str[i + j] && to_find[j] && str[i + j] == to_find[j] && i
				+ j < len)
				j++;
			if (to_find[j] == '\0')
				return (((char *)str) + i);
		}
		i++;
	}
	return (0);
}
