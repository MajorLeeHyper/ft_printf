/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_w_ignore_p.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:30:42 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:37:47 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_w_ignore_p(const char *format, t_bday *flags, va_list *ap)
{
	size_t	len;
	char	*width;

	if (ft_find_w_ignore_p(format, flags) == 0)
		return (0);
	if (format[flags->width_open] == '*')
	{
		flags->width = va_arg(*ap, int);
		if (flags->width < 0)
			flags->width = ft_negative_width(flags->width, flags);
		flags->width_found = 1;
		return (1);
	}
	if (ft_isdigit(format[flags->width_open]) == 1)
	{
		len = ft_str_intlen(format, flags->width_open, flags->close);
		width = ft_strsub(format, flags->width_open, len);
		flags->width = ft_atoi(width);
		flags->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}
