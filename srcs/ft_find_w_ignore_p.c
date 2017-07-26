/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_w_ignore_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:27:55 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:30:19 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_w_ignore_p(const char *format, t_bday *flags)
{
	size_t	index;

	index = flags->open;
	while (index <= flags->close)
	{
		if (ft_isdigit(format[index]) == 1 && format[index] != '0')
		{
			flags->width_open = index;
			flags->width_found = 1;
			return (1);
		}
		if (format[index] == '*')
		{
			flags->width_open = index;
			flags->width_found = 1;
			return (1);
		}
		index++;
	}
	return (0);
}
