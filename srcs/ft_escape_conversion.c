/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:04:10 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:29:52 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width_escape(char *value, t_bday *flags)
{
	size_t	count;
	int		len;
	char	*pad;

	len = ft_compare_int(flags->width, ft_strlen(value)) - ft_strlen(value);
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

size_t	ft_print_flag_escape(char *value, t_bday *flags)
{
	size_t	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += write(1, value, ft_strlen(value));
		count += ft_print_width_escape(value, flags);
	}
	else
	{
		count += ft_print_width_escape(value, flags);
		count += write(1, value, ft_strlen(value));
	}
	return (count);
}

size_t	ft_convert_escape(t_bday *flags, va_list *ap)
{
	size_t	count;
	char	*escape;

	(void)ap;
	count = 0;
	escape = "%";
	count += ft_print_flag_escape(escape, flags);
	return (count);
}
