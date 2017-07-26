/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:11:07 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 22:29:37 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	ft_round(t_bday *flags)
{
	int		index;
	double	round;
	double	divisor;

	index = 0;
	round = 1;
	divisor = 10;
	while (index < flags->precision + 1)
	{
		round /= divisor;
		index++;
	}
	return (round);
}

char	*ft_float_to_string(double num, t_bday *flags)
{
	char	*str;
	char	*type;
	int		index;

	index = 0;
	num += ft_round(flags);
	type = pf_itoa_base((uintmax_t)num, "0123456789", 10);
	str = ft_strnew(ft_stlen(type) + flags->precision + 1);
	while (type[index])
	{
		str[index] = type[index];
		index++;
	}
	str[index++] = '.';
	while (index <= (int)ft_strlen(type) + flags->precision)
	{
		num -= (uintmax_t)num;
		num *= 10;
		str[index] = (uintmax_t)num + '0';
		index++;
	}
	return (str);
}

size_t	ft_convert_float(t_bday *flags, va_list *ap)
{
	char	*value;
	size_t	count;
	double	num;

	count = 0;
	if (flags->precision_found == 0)
		flags->precision = 6;
	else
		flags->precision = ft_compare_int(500, flags->precision);
	num = va_arg(*ap, double);
	if (num < 0)
	{
		num = (double)num * -1;
		flags->negative = 1;
	}
	value = ft_float_to_string(number, flags);
	count += ft_print_flag(value, flags);
	if (value != NULL)
		free(value);
	return (count);
}
