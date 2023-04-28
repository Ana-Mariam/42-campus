/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:20:58 by anmaher-          #+#    #+#             */
/*   Updated: 2023/04/19 12:21:51 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

static char	*ft_clean_totalread(char *str)
{
	int		i;
	char	*totalread;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	totalread = ft_substr(str, i + 1, (ft_strlen(str) - i));
	free(str);
	return (totalread);
}

static char	*ft_free(char **s1, char **s2)
{
	free(*s1);
	free(*s2);
	*s1 = NULL;
	*s2 = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*totalread;
	char		*line;
	int			r;

	r = 1;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
		return (NULL);
	buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!totalread)
		totalread = ft_calloc((1), sizeof(char));
	while (ft_strchr(totalread, '\n') == 0 && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
			return (ft_free(&buff, &totalread));
		buff[r] = '\0';
		totalread = ft_strjoin(totalread, buff);
	}
	free(buff);
	if (!totalread)
		return (NULL);
	line = ft_get_line(totalread);
	totalread = ft_clean_totalread(totalread);
	return (line);
}

/* int	main(void)
{
	int		x;
	int		fd;
	char	*aux;

	x = 0;
	fd = open("/Users/anmaher-/Desktop/archivo.txt", O_RDONLY);
	while (1)
	{
		aux = get_next_line(fd);
		if (aux == NULL)
			break ;
		printf("%s", aux);
		free(aux);
		x++;
	}
	close(fd);	
//system("leaks -q a.out");
} */
