/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:05:21 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 15:44:21 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width(char *str, t_bday *flags)
{
	size_t	count;
	int		len;
	char	*pad;

	len = ft_compare_int(flags->width, ft_strlen(str)) - ft_strlen(str);
	if (len == 0)
		return (0);
	len = ft_widthlen_prefix(len, flags);
	pad = ft_strnew(len);
	if (flags->zero == 1 && flags->minus == 0 &&
			flags->precision_found == 0)
		ft_strchr_replace(pad, '0', 0, len);
	else
		ft_strchr_replace(pad, ' ', 0, len);
	count = write(1, pad, len);
	free(pad);
	return (count);
}
