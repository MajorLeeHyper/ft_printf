/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:14:17 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:57:02 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_parse_wstr(t_wstring *wstring)
{
	wchar_t	*wstr;
	size_t	bytes;

	bytes = 0;
	wstr = wstring->data;
	while (*wstr)
	{
		if (*wstr <= 0x7F)
			bytes++;
		else if (*wstr <= 0x7FF)
			bytes += 2;
		else if (*wstr <= 0xFFFF)
			bytes += 3;
		else if (*wstr <= 0x10FFFF)
			bytes += 4;
		wstr++;
	}
	wstring->bytes = bytes;
}

static void		ft_increment_precision(size_t *bytes, int *precision, int len)
{
	if (len == 1)
	{
		*bytes += 1;
		*precision -= 1;
	}
	if (len == 2)
	{
		*bytes += 2;
		*precision -= 2;
	}
	if (len == 3)
	{
		*bytes += 3;
		*precision -= 3;
	}
	if (len == 4)
	{
		*bytes += 4;
		*precision -= 4;
	}
}

static void		ft_wstr_precision(t_bday *flags, t_wstring *wstring)
{
	wchar_t	*wstr;
	size_t	bytes;
	int		precision;

	bytes = 0;
	wstr = wstring->data;
	precision = flags->precision;
	while (*wstr && precision > 0)
	{
		if (*wstr <= 0x7F)
			ft_increment_precision(&bytes, &precision, 1);
		else if (*wstr <= 0x7FF && precision >= 2)
			ft_increment_precision(&bytes, &precision, 2);
		else if (*wstr <= 0xFFFF && precision >= 3)
			ft_increment_precision(&bytes, &precision, 3);
		else if (*wstr <= 0x10FFFF && precision >= 4)
			ft_increment_precision(&bytes, &precision, 4);
		wstr++;
	}
	wstring->bytes = bytes;
}

static size_t	ft_print_wstr_width(t_bday *flags, size_t len)
{
	size_t	count;
	char	*pad;

	if (flags->width == 0)
		return (0);
	pad = ft_strnew(len);
	if (flags->zero == 1)
		ft_strchr_replace(pad, '0', 0, len);
	else
		ft_strchr_replace(pad, ' ', 0, len);
	count = write(1, pad, len);
	free(pad);
	return (count);
}

size_t			ft_convert_wstring(t_bday *flags, va_list *ap)
{
	size_t		count;
	t_wstring	*wstr;
	size_t		width;

	count = 0;
	wstr = ft_memalloc(sizeof(t_wstring*));
	wstr->data = va_arg(*ap, wchar_t*);
	if (wstr->data == NULL)
		wstr->data = L"(null)";
	ft_parse_wstr(wstr);
	if (flags->precision_found)
		ft_wstr_precision(flags, wstr);
	width = wstr->bytes > flags->width ? 0 : (flags->width - wstr->bytes);
	if (flags->width_found && flags->minus == 0)
		count += ft_print_wstr_width(flags, width);
	count += ft_putwstr(wstr->data, wstr->bytes);
	if (flags->width_found && flags->minus == 1)
		count += ft_print_wstr_width(flags, width);
	if (wstr != NULL)
		free(wstr);
	return (count);
}
