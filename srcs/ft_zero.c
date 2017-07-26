/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 11:16:06 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 11:17:36 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_zero(t_bday *flags)
{
	size_t	count;

	count = 0;
	if (flags->precision_found == 1 && flags->precision == 0)
		count += ft_print_width("", flags);
	else
	{
		count += write(1, "0", 1);
		count += ft_print_width("0", flags);
	}
	return (count);
}
