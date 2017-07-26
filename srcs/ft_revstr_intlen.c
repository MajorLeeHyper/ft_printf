/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr_intlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:59:34 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 16:01:09 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_revstr_intlen(const char *format, t_bday *flags)
{
	int		len;
	size_t	index;

	len = 0;
	index = flags->width_close;
	while (index > flags->open && ft_isdigit(format[index]) == 1)
	{
		len++;
		index--;
	}
	flags->width_open = index + 1;
	return (len);
}
