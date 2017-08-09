/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:55:15 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/31 17:03:03 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits_base(int base, size_t num)
{
	int		digits;

	digits = 1;
	while (num >= (size_t)base)
	{
		num /= base;
		digits++;
	}
	return (digits);
}

char		*ft_itoa_base(int value, int base)
{
	int		digits;
	int		neg;
	int		neg2;
	size_t	num;
	char	*str;

	neg = (value < 0 && base == 10 ? 1 : 0);
	neg2 = (value < 0 && base != 10 ? 1 : 0);
	if (neg == 1 || neg2 == 1)
		num = (size_t)value * -1;
	else
		num = (size_t)value;
	digits = ft_digits_base(base, num);
	str = ft_strnew(digits);
	str[digits + neg] = '\0';
	while (digits-- > 0)
	{
		str[digits + neg] = (num % base) + (num % base > 9 ? 'A' - 10 : '0');
		num /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
