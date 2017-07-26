/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:01:58 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 14:22:07 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_flag(char *str, t_bday *flags)
{
	size_t	count;

	count = 0;
	if (flags->zero == 1 && flags->minus == 0)
	{
		count += ft_print_prefix(flags);
		count += ft_print_width(str, flags);
		count += write(1, str, ft_strlen(str));
	}
	else if (flags->minus == 1)
	{
		count += ft_print_prefix(flags);
		count += write(1, str, ft_strlen(str));
		count += ft_print_width(str, flags);
	}
	else
	{
		count += ft_print_width(str, flags);
		count += ft_print_prefix(flags);
		count += write(1, str, ft_strlen(str));
	}
	return (count);
}
