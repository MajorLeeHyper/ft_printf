/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 20:59:45 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:05:11 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_precision(const char *format, t_bday *flags, va_list *ap)
{
	size_t	len;
	char	*precision;

	if (flags->precision_found == 0)
		return (0);
	if (format[flags->precision_index + 1] == '*')
	{
		flags->precision = va_arg(*ap, int);
		flags->precision_wild_found = 1;
		if (flags->precision < 0)
			flags->precision_found = 0;
		return (1);
	}
	ft_skip_wild_arg_prec(format, flags, ap);
	if (ft_isdigit(format[flags->precision_index + 1]) == 1)
	{
		flags->precision_index += 1;
		len = ft_str_intlen(format, flags->precision_index, flags->close);
		precision = ft_strsub(format, flags->precision_index, len);
		flags->precision = ft_atoi(precision);
		free(precision);
		return (1);
	}
	return (-1);
}
