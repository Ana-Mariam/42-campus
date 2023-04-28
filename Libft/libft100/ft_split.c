/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:19:07 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/05 15:45:36 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	i;
	size_t	countwords;

	i = 0;
	countwords = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			countwords++;
		i++;
	}
	return (countwords);
}

static size_t	ft_countletters(const char *s, char c, size_t i)
{
	size_t	l;

	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		l++;
		i++;
	}
	return (l);
}

static void	ft_free(char **array)
{
	size_t	j;

	j = 0;
	while (array[j] != 0)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

static char	**ft_makearray(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			array[j] = ft_substr(s, i, (ft_countletters(s, c, i)));
			if (array[j] == '\0')
			{
				ft_free(array);
				return (NULL);
			}
			i = i + (ft_countletters(s, c, i));
			j++;
		}
		else if (s[i] != '\0')
			i++;
	}
	array[j] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!array)
		return (NULL);
	return (ft_makearray(array, s, c));
}

/*
int	main(void)
{
	char	*s;
	char	c;
	char	**array;
	int		j;

	s = "nonempty";
	
	c = '\0';
	array = ft_split(s, c);
	j = 0;
	while (array[j] != 0)
	{
		printf("%s\n", array[j]);
		j++;
	}
	return (0);
	
}*/
