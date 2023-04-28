/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmaher- <anmaher-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:15:45 by anmaher-          #+#    #+#             */
/*   Updated: 2023/03/27 17:55:58 by anmaher-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = malloc(len * (sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char to_upper(unsigned int index, char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return (c - 'a' + 'A');
    }
    return (c);
}

int	main(void)
{
	const char	*input_str;
	char		*upper_str;

    input_str = "Convert this String to Uppercase";
    upper_str = ft_strmapi(input_str, to_upper);
    if (upper_str)
    {
        printf("Original string: %s\n", input_str);
        printf("Uppercase string: %s\n", upper_str);
        free(upper_str);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return (0);
}
*/