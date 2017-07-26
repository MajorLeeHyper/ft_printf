/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:43:23 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 20:31:29 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_skip_wild_arg_width(const char *format, t_bday *flags, va_list *ap)
{
	int		skip;
	size_t	index;

	index = flags->open;
	if (flags->width_wild_found == 0)
	{
		while (index < flags->close && format[index] != '.')
		{
			if (format[index] == '*')
			{
				skip = va_arg(*ap, int);
				return ;
			}
			index++;
		}
	}
}

int		ft_parse_width(const char *format, t_bday *flags, va_list *ap)
{
	size_t	len;
	char	*width;

	if (ft_find_width(format, flags) == 0)
		return (0);
	if (format[flags->width_close] == '*')
	{
		flags->width = va_arg(*ap, int);
		if (flags->width < 0)
			flags->width = ft_negative_width(flags->width, flags);
		flags->width_found = 1;
		return (1);
	}
	ft_skip_wild_arg_width(format, flags, ap);
	if (ft_isdigit(format[flags->width_close]) == 1)
	{
		len = ft_revstr_intlen(format, flags);
		width = ft_strsub(format, flags->width_open, len);
		flags->width = ft_atoi(width);
		flags->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}
