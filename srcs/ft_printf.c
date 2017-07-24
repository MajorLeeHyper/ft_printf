/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:50:37 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/24 14:29:58 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** temp
*/

int		ft_next_arg(va_list ap, char **str)
{
	return (1);
}


int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		j;
	int		k;
	char	*str;

	j = 0;
	k = 0;
	if ((i = ft_strchr_count((char *)format, '%')) == 0)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	str = ft_strdup(format);
	va_start(ap, format);
	while (i-- >= 0)
	{
		if ((l - ft_next_arg(ap, &str)) == 1)
			k++;
		else if (l == -1)
			return (0);
	}
	va_end(ap);
	return (1);
}
