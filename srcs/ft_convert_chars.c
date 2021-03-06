/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:37:32 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:28:28 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width_char(t_bday *flags)
{
	size_t	count;
	int		len;
	char	*pad;

	len = ft_compare_int(flags->width, 1) - 1;
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

size_t	ft_print_flag_char(char *value, t_bday *flags)
{
	size_t	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += write(1, value, 1);
		count += ft_print_width_char(flags);
	}
	else
	{
		count += ft_print_width_char(flags);
		count += write(1, value, 1);
	}
	return (count);
}

size_t	ft_convert_char(t_bday *flags, va_list *ap)
{
	size_t	count;
	char	c;

	count = 0;
	c = va_arg(*ap, int);
	if (flags->precision > 0 && c != '\0')
		count += write(1, "*", 1);
	else
		count += ft_print_flag_char(&c, flags);
	return (count);
}
