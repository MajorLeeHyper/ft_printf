/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:38:02 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:40:12 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_parse_width_only(const char *format, t_bday *flags, va_list *ap)
{
	char	*width;
	int		len;

	if (format[flags->width_open] == '*')
	{
		flags->width = va_arg(*ap, int);
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->minus = 1;
		}
		flags->width -= 1;
		flags->width_found = 1;
		return (1);
	}
	if (ft_isdigit(format[flags->width_open]) == 1)
	{
		len = ft_str_intlen(format, flags->width_open, flags->close + 1);
		width = ft_strsub(format, flags->width_open, len);
		flags->width = ft_atoi(width) - 1;
		flags->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}
