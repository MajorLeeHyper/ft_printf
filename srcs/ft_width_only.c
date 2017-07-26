/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:25:34 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:27:32 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_only(const char *format, t_bday *flags)
{
	size_t	index;

	index = flags->open + 1;
	while (format[index])
	{
		if (ft_isdigit(format[index]) == 1 || format[index] == '*')
		{
			while (ft_isdigit(format[index]) == 1 || format[index] == '*')
				index++;
			flags->close = index - 1;
			return (1);
		}
		index++;
	}
	return (0);
}
