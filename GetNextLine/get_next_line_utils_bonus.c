/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:24:56 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/19 12:26:19 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*y;
	size_t	i;

	i = 0;
	y = malloc(count * size);
	if (!y)
		return (NULL);
	while (i < count * size)
		y[i++] = '\0';
	return (y);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2)) * (sizeof(char)) + 1);
	if (!s3)
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i + j] = s2[j];
		j++;
	}
	free(s1);
	s3[i + j] = '\0';
	return (s3);
}

int	ft_strchr(char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s)
	{
		if (*s != chr)
			s++;
		else
			return (1);
	}
	if (chr == '\0')
		return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*subs;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = (char *)malloc((len + 1) * (sizeof(char)));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
