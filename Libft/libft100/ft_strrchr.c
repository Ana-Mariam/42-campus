/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:35:54 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/16 16:09:31 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	int		i;
	char	*str;

	chr = (char)c;
	i = ft_strlen(s);
	str = (char *)s;
	while (i >= 0)
	{
		if (str[i] == chr)
			return (&str[i]);
		else
			i--;
	}
	return (NULL);
}
