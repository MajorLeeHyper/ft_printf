/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:05:20 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:06:45 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_precision(const char *format, t_bday *flags)
{
	size_t	index;

	index = flags->open;
	while (index < flags->close)
	{
		if (format[index] == '.')
		{
			flags->precision_index = index;
			flags->precision_found = 1;
			return (1);
		}
		index++;
	}
	return (0);
}
