/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 22:20:34 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 14:22:44 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_base(uintmax_t num, size_t base)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= base;
		++len;
	}
	return (len);
}

char		*pf_itoa_base(uintmax_t num, char *base_chars, size_t base)
{
	char	*str;
	int		len;

	len = ft_intlen_base(num, base);
	if ((str = ft_strnew(len--)) == NULL)
		return (NULL);
	if (num == 0)
		str[0] = base_chars[0];
	while (num)
	{
		str[len--] = base_chars[(num % base)];
		num /= base;
	}
	return (str);
}
