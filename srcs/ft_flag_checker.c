/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:23:57 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:31:10 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_close_flag(const char *format, t_bday *flags, size_t index)
{
	while (format[index])
	{
		if (ft_flag_char(format[index]))
		{
			flags->close = index;
			flags->type = format[index];
			return (0);
		}
		if (ft_false_flag(format[index]))
		{
			flags->close = index;
			flags->unterminated_char = format[index];
			return (1);
		}
		index++;
	}
	return (1);
}

int		ft_open_flag(const char *format, t_bday *flags)
{
	size_t	index;

	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			flags->open = index;
			if (ft_close_flag(format, flags, (index + 1)))
				return (2);
			return (1);
		}
		index++;
	}
	return (0);
}

int		ft_parse_prefix(const char *format, t_bday *flags)
{
	size_t	index;

	index = flags->open;
	while (index < flags->close)
	{
		if (format[index] == '#')
			flags->hash = 1;
		if (format[index] == '0' && ft_isdigit(format[index - 1]) == 0)
			flags->zero = 1;
		if (format[index] == '-')
			flags->minus = 1;
		if (format[index] == '+')
			flags->plus = 1;
		if (format[index] == ' ')
			flags->space = 1;
		if (format[index] == 'j')
			flags->j_len = 1;
		if (format[index] == 'z')
			flags->z_len = 1;
		index++;
	}
	return (0);
}

int		ft_parse_len(const char *format, t_bday *flags)
{
	size_t	index;

	index = flags->open;
	while (index < flags->close)
	{
		if (format[index] == 'h' && format[index + 1] != 'h')
			flags->h_len = 1;
		if (format[index] == 'h' && format[index + 1] == 'h')
		{
			flags->hh_len = 1;
			index++;
		}
		if (format[index] == 'l' && format[index + 1] != 'l')
			flags->l_len = 1;
		if (format[index] == 'l' && format[index + 1] == 'l')
		{
			flags->ll_len = 1;
			index++;
		}
		index++;
	}
	return (0);
}

int		ft_assign_flag(const char *format, t_bday *flags, va_list *ap)
{
	int		cake;

	if ((cake = ft_open_flag(format, flags)) == 0)
	{
		free(flags);
		return (0);
	}
	if (cake == 2)
		return (2);
	ft_parse_prefix(format, flags);
	ft_parse_width(format, flags, ap);
	ft_parse_precision(format, flags, ap);
	ft_parse_len(format, flags);
	return (1);
}
