/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:37:32 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:20:02 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width_char(t_bday *flags)
{
	size_t	count;
	int		len;
	char	*extra;

	len = ft_compare_int(flags->width, 1) - 1;
	if (len == 0)
		return (0);
	if (flags->zero_flag == 1 && flags->minus_flag == 0)
	{
		extra = ft_strnew(len);
		ft_strchar_replace(extra, '0', 0, len);
		count += write(1, extra, len);
		free(extra);
	}
	else
	{
		extra = ft_strnew(len);
		ft_strchr_replace(extra, ' ', 0, len);
		count += write(1, extra, len);
		free(extra);
	}
	return (cont);
}


size_t	ft_print_flag_char(char *value, t_bday *flags)
{
	size_t	count;

	count = 0;
	if (flags->minus_flag == 1)
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
