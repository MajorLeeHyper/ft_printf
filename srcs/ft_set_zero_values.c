/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_zero_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 16:15:13 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/24 16:18:15 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_zero_values(t_bday *flags)
{
	flags->open = 0;
	flags->close = 0;
	flags->type = '0';
	flags->width = 0;
	flags->width_found = 0;
	flags->width_wild_found = 0;
	flags->width_open = 0;
	flags->width_close = 0;
	flags->precision = 0;
	flags->precision_found = 0;
	flags->precision_wild_found = 0;
	flags->precision_index = 0;
	flags->negative = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->h_len = 0;
	flags->l_len = 0;
	flags->ll_len = 0;
	flags->j_len = 0;
	flags->z_len = 0;
	flags->unterminated_char = '0';
}
