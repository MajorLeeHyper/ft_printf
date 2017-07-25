/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unterminated.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:12:14 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 12:34:13 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_force_close(const char *format, t_bday *flags)
{
	size_t	i;

	i = flags->open;
	if (flags->unterminated_char != '0')
		return (1);
	if (ft_width_only(format, flags) == 1)
		return (2);
	if (ft_skip_flag(format, flags) == 1)
		return (3);
	if (flag->close == 0)
	{
		while (format[i])
			i++;
		flag->close = i;
	}
	return (0);
}

size_t	ft_process_unterm(const char *format, t_bday *flags, va_list *ap)
{
	size_t	count;
	int		check;

	count = 0;
	if ((check = ft_force_close(format, flags)) == 0)
	{
		flags->exit = 1;
		return (0);
	}
	if (check == 2)
	{
		ft_parse_prefix(format, flags);
		ft_find_w_ignore_p(format, flags);
		ft_parse_width_only(format, flags, ap);
		count += ft_print_width_only(flags);
		return (count);
	}
	if (check == 3)
		return (count);
	ft_parse_prefix(format, flags);
	ft_parse_w_ignore_p(format, flags, ap);
	count += ft_print_flag_string(&flags->unterminated_char, flags);
	return (count);
}
