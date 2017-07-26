/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:35:06 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 22:45:32 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_dlong(t_bday *flags, va_list *ap)
{
	char		c;
	char		*value;
	size_t		count;
	intmax_t	num;

	c = flags->type;
	count = 0;
	if (c == 'D')
	{
		num = va_arg(*ap, intmax_t);
		num = (long)num;
		num = ft_negative_num(num, flags);
		value = pf_itoa_base(num, "0123456789", 10);
		ft_precision_int_value(&value, flags);
		count += ft_print_flag(value, flags);
		if (value != NULL)
			free(value);
	}
	return (count);
}

size_t	ft_convert_ulong(t_bday *flags, va_list *ap)
{
	char		c;
	char		*value;
	size_t		count;
	intmax_t	num;

	c = flags->type;
	count = 0;
	if (c == 'U')
	{
		num = va_arg(*ap, uintmax_t);
		num = (unsigned long)num;
		value = pf_itoa_base(num, "0123456789", 10);
		ft_precision_int_value(&value, flags);
		count += ft_print_flag(value, flags);
		if (value != NULL)
			free(value);
	}
	return (count);
}

size_t	ft_convert_olong(t_bday *flags, va_list *ap)
{
	char		c;
	char		*value;
	size_t		count;
	intmax_t	num;

	c = flags->type;
	count = 0;
	if (c == 'O')
	{
		num = va_arg(*ap, uintmax_t);
		num = (unsigned long)num;
		value = pf_itoa_base(num, "01234567", 8);
		ft_precision_int_value(&value, flags);
		flags->minus = 0;
		flags->plus = 0;
		count += ft_print_flag(value, flags);
		if (value != NULL)
			free(value);
	}
	return (count);
}
