/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthlen_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:45:04 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:59:26 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widthlen_prefix(int len, t_bday *flags)
{
	char	c;

	c = flags->type;
	if ((c == 'o' || c == 'O') && flags->hash == 1)
		return (len - 1);
	if (c == 'p')
		return (len - 2);
	if ((c == 'x' || c == 'X') && flags->hash == 1)
		return (len - 2);
	if (flags->negative == 1)
		return (len - 1);
	if (flags->negative == 0 && flags->plus == 1)
		return (len - 1);
	if (flags->negative == 0 && flags->plus == 0 && flags->space == 1 &&
			c != '%')
		return (len - 1);
	return (len);
}
