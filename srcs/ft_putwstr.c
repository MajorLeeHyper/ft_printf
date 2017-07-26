/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:46:05 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 12:50:01 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putwstr(wchar_t *str, size_t bytes)
{
	size_t	count;

	count = 0;
	while (*str && count < bytes)
	{
		if (*str <= 0x7F)
			count++;
		else if (*str <= 0x7FF)
			count += 2;
		else if (*str <= 0xFFFF)
			count += 3;
		else if (*str <= 0x10FFFF)
			count += 4;
		if (count <= bytes)
			ft_putwchar(*str);
		str++;
	}
	return (count);
}
