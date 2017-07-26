/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_int_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:09:39 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/26 13:13:42 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision_int_value(char **value, t_bday *flags)
{
	int		len;
	char	*tmp;

	len = (ft_compare_int(flags->precision, ft_strlen(*value)) -
			ft_strlen(*value));
	if (flags->type == 'o' && flags->hash == 1 && flags->precision >= 1)
		len -= 1;
	if (len == 0 && *value[0] == '0' && flags->precision_found == 1)
	{
		free(*value);
		tmp = ft_strnew(0);
		*value = tmp;
		return ;
	}
	if (len == 0)
		return ;
	tmp = ft_strnew(flags->precision);
	ft_strchr_replace(tmp, '0', 0, len);
	tmp += len;
	tmp = ft_strcpy(tmp, *value);
	free(*value);
	*value = tmp - len;
}
