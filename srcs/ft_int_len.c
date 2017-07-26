/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:40:58 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 11:22:54 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_int_len(intmax_t num, t_bday *flags)
{
	if (flags->z_len == 1)
		num = (size_t)num;
	else if (flags->j_len == 1)
		num = (intmax_t)num;
	else if (flags->l_len == 1)
		num = (long)num;
	else if (flags->ll_len == 1)
		num = (long long)num;
	else if (flags->h_len == 1)
		num = (short int)num;
	else if (flags->hh_len == 1)
		num = (signed char)num;
	else
		num = (int)num;
	return (num);
}
