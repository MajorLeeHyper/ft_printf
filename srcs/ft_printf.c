/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:50:37 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 11:29:35 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initialize_identifier(t_convert *identifier)
{
	identifier['%'] = &ft_convert_escape;
	identifier['s'] = &ft_convert_str;
	identifier['S'] = &ft_convert_wstr;
	identifier['c'] = &ft_convert_char;
	identifier['C'] = &ft_convert_char;
	identifier['i'] = &ft_convert_int;
	identifier['d'] = &ft_convert_int;
	identifier['f'] = &ft_convert_float;
	identifier['F'] = &ft_convert_float;
	identifier['D'] = &ft_convert_dlong;
	identifier['u'] = &ft_convert_uint;
	identifier['U'] = &ft_convert_ulong;
	identifier['o'] = &ft_convert_octal;
	identifier['O'] = &ft_convert_olong;
	identifier['x'] = &ft_convert_hex_lc;
	identifier['X'] = &ft_convert_hex_uc;
	identifier['p'] = &ft_convert_pointer;
}

t_convert	ft_identify_flag(char c)
{
	static t_convert	*identifier;

	if (identifier == NULL)
	{
		identifier = ft_memalloc(sizeof(*identifier) * 256);
		if (identifier != NULL)
			ft_initialize_identifier(identifier);
	}
	return (identifier[(int)c]);
}

size_t		ft_flag_check(t_bday *flags, va_list *ap)
{
	size_t		count;
	t_convert	convert;

	if (flags->type == 's' && flags->l_len == 1)
		flags->type == 'S';
	convert = ft_identify_flag(flags->type);
	count = convert(flags, ap);
	return (count);
}

int			ft_parse_input(const char *format, va_list *ap, t_bday *flags)
{
	int			count;
	size_t		ret;

	ret = 0;
	while ((count = ft_assign_flag(format, flags, ap)) != 0)
	{
		if (count == 1)
		{
			ret += write(1, format, flags->open);
			format += (flags->open + (flags->close - flags->open) + 1);
			ret += ft_flag_check(flags, ap);
		}
		else if (count == 2)
		{
			ret += write(1, format, flags->open);
			ret += ft_process_uterm(format, flags, ap);
			if (flags->exit == 1)
				return (ret);
			format += (flags->open + (flags->close - flags->open) + 1);
		}
		ft_set_zero_values(flags);
	}
	ret += write(1, format, ft_strlen(format));
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_bday		*flags;

	va_start(ap, format);
	flags = ft_memalloc(sizeof(t_bday));
	if (flags == NULL)
		return (-1);
	ft_set_zero_values(flags);
	count = ft_parse_input(format, &ap, flags);
	va_end(ap);
	return (count);
}
