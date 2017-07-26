/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:53:59 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:43:02 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_prefix(t_bday *flags)
{
	size_t	count;
	char	c;

	count = 0;
	c = flags->type;
	if ((c == 'o' || c == 'O') && flags->hash == 1)
		count += write(1, "0", 1);
	if (c == 'p' || (c == 'x' && flags->hash == 1))
		count += write(1, "0x", 2);
	if (c == 'X' && flags->hash == 1)
		count += write(1, "0X", 2);
	if (flags->negative == 1)
		count += write(1, "-", 1);
	if (flags->negative == 0 && flags->plus == 1)
		count += write(1, "+", 1);
	if (flags->negative == 0 && flags->plus == 0 && flags->space == 1 &&
			c != '%')
		count += write(1, " ", 1);
	return (count);
}
