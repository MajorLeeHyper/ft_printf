/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:48:42 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:41:31 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width_pointer(char *str, t_bday *flags)
{
	size_t		count;
	int			len;
	char		*pad;

	len = ft_compare_int(flags->width, (ft_strlen(str) + 2)) -
		(ft_strlen(str) + 2);
	if (len == 0)
		return (0);
	pad = ft_strnew(len);
	if (flags->zero == 1 && flags->minus == 0)
		ft_strchr_replace(pad, '0', 0, len);
	else
		ft_strchr_replace(pad, ' ', 0, len);
	count = write(1, pad, len);
	free(pad);
	return (count);
}

size_t	ft_print_flag_pointer(char *str, t_bday *flags)
{
	size_t		count;

	count = 0;
	if (flags->zero == 1)
	{
		count += write(1, "0x", 2);
		count += ft_print_width_pointer(str, flags);
		count += write(1, str, ft_strlen(str));
	}
	else if (flags->minus == 1)
	{
		count += write(1, "0x", 2);
		count += write(1, str, ft_strlen(str));
		count += ft_print_width_pointer(str, flags);
	}
	else
	{
		count += ft_print_width_pointer(str, flags);
		count += write(1, "0x", 2);
		count += write(1, str, ft_strlen(str));
	}
	return (count);
}

size_t	ft_convert_pointer(t_bday *flags, va_list *ap)
{
	char		*str;
	size_t		count;
	uintmax_t	num;

	count = 0;
	num = va_arg(*ap, uintmax_t);
	str = pf_itoa_base(num, "0123456789abcdef", 16);
	if (num == 0 && flags->precision_found == 1 && flags->precision == 0)
	{
		count += write(1, "0x", 2);
		if (str != NULL)
			free(str);
		return (count);
	}
	ft_precision_int_value(&str, flags);
	count += ft_print_flag_pointer(str, flags);
	if (str != NULL)
		free(str);
	return (count);
}
