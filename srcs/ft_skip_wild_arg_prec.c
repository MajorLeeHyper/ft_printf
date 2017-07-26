/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_wild_arg_prec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:07:32 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:09:20 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_skip_wild_arg_prec(const char *format, t_bday *flags, va_list *ap)
{
	int		skip;
	size_t	index;

	index = flags->precision_index + 1;
	if (flags->precision_wild_found == 0)
	{
		while (index < flags->close)
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
