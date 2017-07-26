/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 10:43:59 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 10:46:37 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_uint_len(uintmax_t num, t_bday *flags)
{
	if (flags->z_len == 1)
		num = (size_t)num;
	else if (flags->j_len == 1)
		num = (uintmax_t)num;
	else if (flags->l_len == 1)
		num = (unsigned long)num;
	else if (flags->ll_len == 1)
		num = (unsigned long long)num;
	else if (flags->h_len == 1)
		num = (unsigned short int)num;
	else if (flags->hh_len == 1)
		num = (unsigned char)num;
	else
		num = (unsigned int)num;
	return (num);
}
