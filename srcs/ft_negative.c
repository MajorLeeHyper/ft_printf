/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:48:27 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 10:50:35 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_negative(intmax_t num, t_bday *flags)
{
	if (num < 0)
	{
		num = -num;
		flags->negaitve = 1;
	}
	return (num);
}

intmax_t	ft_negative_width(intmax_t num, t_bday *flags)
{
	if (num < 0)
	{
		num = -num;
		flags->minus = 1;
	}
	return (num);
}
