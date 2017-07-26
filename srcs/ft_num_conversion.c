/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:00:48 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 11:27:00 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_int(t_bday *flags, va_list *ap)
{
	char		*value;
	size_t		count;
	intmax_t	num;

	count = 0;
	num = va_arg(*ap, intmax_t);
	num = ft_int_len(num, flags);
	num = ft_negative(num, flags);
	value = pf_itoa_base(num, "0123456789", 10);
	ft_precision_int_value(&value, flags);
	count += ft_print_flag(value, flag);
	if (value != NULL)
		free(value);
	return (count);
}

size_t	ft_convert_uint(t_bday *flags, va_list *ap)
{
	char		*value;
	size_t		count;
	uintmax_t	num;

	count = 0;
	ft_set_prefix(flags);
	num = va_arg(*ap, uintmax_t);
	num = ft_uint_len(num, flags);
	value = pf_itoa_base(num, "0123456789", 10);
	ft_precision_int_value(&value, flags);
	count += ft_prit_flag(value, flags);
	if (value != NULL)
		free(value);
	return (count);
}

size_t	ft_convert_octal(t_bday *flags, va_list *ap)
{
	char		*value;
	size_t		count;
	uintmax_t	num;

	ft_set_prefix(flags);
	num = va_arg(*ap, uintmax_t);
	num = ft_uint_len(num, flags);
	if (num == 0 && flags->hash == 0)
	{
		count = ft_zero(flags);
		return (count);
	}
	if (num == 0 && flags->hash == 1)
	{
		count = ft_print_prefix(flags);
		return (count);
	}
	value = pf_itoa_base(num, "01234567", 8);
	ft_precision_int_value(&value, flags);
	count = ft_print_flag(value, flag);
	if (value != NULL)
		free(value);
	return (count);
}

size_t	ft_convert_upper_hex(t_bday *flags, va_list *ap)
{
	char		*value;
	size_t		count;
	uintmax_t	num;

	ft_set_prefix(flags);
	num = va_arg(*ap, uintmax_t);
	num = ft_uint_len(num, flags);
	if (num == 0)
	{
		count = ft_zero(flags);
		return (count);
	}
	value = pf_itoa_base(num, "0123456789ABCDEF", 16);
	ft_precision_int_value(&value, flags);
	count = ft_print_flag(value, flags);
	if (value != NULL)
		free(value);
	return (count);
}

size_t	ft_convert_lower_hex(t_bday *flags, va_list *ap)
{
	char		*value;
	size_t		count;
	uintmax_t	num;

	ft_set_prefix(flags);
	num = va_arg(*ap, uintmax_t);
	num = ft_uint_len(num, flags);
	if (num == 0)
	{
		count = ft_zero(flags);
		return (count);
	}
	value = pf_itoa_base(num, "0123456789abcdef", 16);
	ft_precision_int_value(&value, flags);
	count = ft_print_flag(value, flags);
	if (value != NULL)
		free(value);
	return (count);
}
