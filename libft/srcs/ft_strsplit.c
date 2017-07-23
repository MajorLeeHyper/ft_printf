/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:38:10 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/01 21:17:52 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

static size_t	ft_count_split(char *str, char c)
{
	size_t	i;
	size_t	count;
	int		space_check;

	count = 0;
	i = 0;
	space_check = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (space_check == 1)
			{
				count++;
				space_check = 0;
			}
		}
		else if (space_check == 0)
			space_check = 1;
		i++;
	}
	if (str[i - 1] != c && i != 0)
		count++;
	return (count);
}

static char		*ft_strcpy_split(char *dest, char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	char	*str;
	size_t	i[3];

	if (!s)
		return (NULL);
	i[0] = 0;
	i[2] = 0;
	i[1] = ft_count_split((char*)s, c);
	if (!(array = (char**)malloc(sizeof(char*) * (i[1] + 1))))
		return (NULL);
	while (i[0] < i[1])
	{
		while (s[i[2]] == c)
			i[2]++;
		if (!(str = ft_strnew(ft_strlenc((char*)&s[i[2]], c))))
			return (NULL);
		array[i[0]] = str;
		ft_strcpy_split(str, (char*)&s[i[2]], c);
		while (s[i[2]] != c)
			i[2]++;
		i[0]++;
	}
	array[i[0]] = NULL;
	return (array);
}
