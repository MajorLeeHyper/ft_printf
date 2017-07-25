/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:41:54 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 14:33:35 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_false_flag(char c)
{
	char	*nope;

	nope = "yYbBkKmMrRtTwWHIJNPQVZ";
	while (*nope)
	{
		if (*nope == c)
			return (1);
		nope++;
	}
	return (0);
}

int		ft_flag_char(char c)
{
	char	*yup;

	yup = "sSpdDioOuUxXcCfF%";
	while (*yup)
	{
		if (*yup == c)
			return (1);
		yup++;
	}
	return (0);
}

int		ft_valid_flag(char c)
{
	char	*valid;

	valid = "0#+- lhzj%";
	while (*valid)
	{
		if (*valid == c)
			return (0);
		valid++;
	}
	return (1);
}

int		ft_skip_flag(const char *format, t_bday *flags)
{
	size_t	index;

	index = flags->open + 1;
	while (format[index])
	{
		if (ft_valid_flag(format[index]) == 1)
		{
			flags->close = index - 1;
			return (1);
		}
		index++;
	}
	return (0);
}
