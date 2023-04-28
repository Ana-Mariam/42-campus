/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:29:38 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/17 17:14:57 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	int		len;
	size_t	i;

	len = ft_strlen(s1) + 1;
	d = malloc(len * (sizeof(char)));
	i = 0;
	if (!d)
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			d[i] = s1[i];
			i++;
		}
		d[i] = '\0';
	}
	return (d);
}
