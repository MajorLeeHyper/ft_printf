/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:31:26 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:52:58 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_text_value(char *str, t_bday *flags)
{
	int		len;
	char	*precision_value;

	len = ft_compare_int(ft_strlen(str), flags->precision);
	precision_value = ft_strsub(str, 0, len);
	return (precision_value);
}

size_t	ft_print_width_string(char *str, t_bday *flags)
{
	size_t	count;
	int		len;
	char	*pad;

	if (str == NULL)
		len = ft_compare_int(flags->width, 0);
	else
		len = ft_compare_int(flags->width, ft_strlen(str)) - ft_strlen(str);
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

size_t	ft_print_flag_string(char *str, t_bday *flags)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		count += ft_print_width_string(str, flags);
	if (flags->minus == 1)
	{
		count += write(1, str, ft_strlen(str));
		count += ft_print_width_string(str, flags);
	}
	else
	{
		count += ft_print_width_string(str, flags);
		count += write(1, str, ft_strlen(str));
	}
	return (count);
}

size_t	ft_convert_string(t_bday *flags, va_list *ap)
{
	size_t	count;
	char	*str;

	count = 0;
	str = va_arg(*ap, char*);
	if ((str == NULL || ft_strcmp(str, "(null)") == 0) && flags->zero == 1)
	{
		count += ft_print_width_string(str, flags);
		return (count);
	}
	else if (str == NULL || ft_strcmp(str, "(null)") == 0)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	else
	{
		if (flags->precision_found == 1)
			str = ft_precision_text_value(str, flags);
		count = ft_print_flag_string(str, flags);
	}
	return (count);
}
