/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_intlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 16:01:23 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 16:02:43 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_intlen(const char *format, size_t index, size_t close)
{
	int		len;

	len = 0;
	while (index < close && ft_isdigit(format[index]) == 1)
	{
		len++;
		index++;
	}
	return (len);
}
