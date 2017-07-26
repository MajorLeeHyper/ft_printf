/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width_only.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 21:42:18 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 21:45:24 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_width_only(t_bday *flags)
{
	size_t	count;
	char	*pad;

	count = 0;
	if (flags->zero == 1)
	{
		pad = ft_strnew(flags->width);
		ft_strchr_replace(pad, '0', 0, flags->width);
		count = write(1, pad, flags->width);
		free(pad);
	}
	else
	{
		pad = ft_strnew(flags->width);
		ft_strchr_replace(pad, ' ', 0, flags->width);
		count = write(1, pad, flags->width);
		free(pad);
	}
	return (count);
}
