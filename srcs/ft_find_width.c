/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:54:18 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 15:57:15 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_width(const char *format, t_bday *flags)
{
	size_t	index;

	if (ft_find_precision(format, flags) == 1)
		index = flags->precision_index - 1;
	else
		index = flags->close;
	while (index > flags->open)
	{
		if (ft_isdigit(format[index]) == 1)
		{
			flags->width_close = index;
			flags->width_found = 1;
			return (1);
		}
		if (format[index] == '*')
		{
			flags->width_close = index;
			flags->width_wild_found = 1;
			flags->width_found = 1;
			return (1);
		}
		index--;
	}
	return (0);
}
